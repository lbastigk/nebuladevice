#!/bin/bash
set -uo pipefail

cd "$(dirname "$0")"

usage() {
  printf 'Usage: %s [--list | <legacy-test-name>]\n' "$0"
  printf '\n'
  printf 'Without an argument, build and run every legacy test.\n'
  printf 'With a test name, build and run only that test.\n'
  printf 'Set NEBULA_TEST_TIMEOUT_SECONDS to limit each test run.\n'
}

mapfile -t test_names < <(
  find src/NebulaDeviceTests -mindepth 1 -maxdepth 1 -type d \
    -printf '%f\n' | sort
)

case "${1:-}" in
  --help|-h)
    usage
    exit 0
    ;;
  --list|-l)
    printf '%s\n' "${test_names[@]}"
    exit 0
    ;;
  "")
    selected_test=""
    ;;
  -*)
    usage >&2
    exit 2
    ;;
  *)
    selected_test="$1"
    if [ "$#" -ne 1 ]; then
      usage >&2
      exit 2
    fi
    if ! printf '%s\n' "${test_names[@]}" | grep -Fxq "$selected_test"; then
      printf 'Unknown legacy test: %s\n\n' "$selected_test" >&2
      printf 'Available tests:\n' >&2
      printf '  %s\n' "${test_names[@]}" >&2
      exit 2
    fi
    ;;
esac

architecture="${NEBULA_MINGW_ARCH:-32}"
case "$architecture" in
  32)
    toolchain="$PWD/cmake/mingw32-toolchain.cmake"
    default_build_dir="build-legacy-mingw32"
    build_option="-DNEBULA_BUILD_MINGW32=ON"
    ;;
  64)
    toolchain="$PWD/cmake/mingw64-toolchain.cmake"
    default_build_dir="build-legacy-mingw64"
    build_option="-DNEBULA_BUILD_MINGW64=ON"
    ;;
  *)
    printf 'Unsupported NEBULA_MINGW_ARCH: %s (expected 32 or 64)\n' "$architecture" >&2
    exit 2
    ;;
esac

build_dir="${NEBULA_LEGACY_BUILD_DIR:-$default_build_dir}"
jobs="${NEBULA_BUILD_JOBS:-2}"
runner="${NEBULA_TEST_RUNNER:-wine}"
test_timeout="${NEBULA_TEST_TIMEOUT_SECONDS:-120}"
if ! [[ "$test_timeout" =~ ^[1-9][0-9]*$ ]]; then
  printf 'Invalid NEBULA_TEST_TIMEOUT_SECONDS: %s (expected a positive integer)\n' \
    "$test_timeout" >&2
  exit 2
fi
log_dir="$build_dir/legacy-test-logs"

cmake -S . -B "$build_dir" \
  -DCMAKE_TOOLCHAIN_FILE="$toolchain" \
  "$build_option" \
  -DNEBULA_BUILD_LEGACY_TESTS=ON \
  -DNEBULA_BUILD_TESTS=OFF
configure_status=$?
if [ "$configure_status" -ne 0 ]; then
  printf '%-36s %s\n' "Configuration" "Failed due to build error"
  exit "$configure_status"
fi

mkdir -p "$log_dir"

successes=0
build_failures=0
test_failures=0

if [ -n "$selected_test" ]; then
  tests_to_run=("$selected_test")
  printf 'Legacy test: %s\n\n' "$selected_test"
else
  tests_to_run=("${test_names[@]}")
  printf '%-36s %s\n' "Legacy test" "Result"
  printf '%-36s %s\n' "------------" "------"
fi

for test_name in "${tests_to_run[@]}"; do
  target="legacy_${test_name}"
  executable="$build_dir/${target}.exe"

  build_log="$log_dir/${test_name}.build.log"
  run_log="$log_dir/${test_name}.run.log"

  if ! cmake --build "$build_dir" --target "$target" --parallel "$jobs" \
      >"$build_log" 2>&1; then
    printf '%-36s %s (see %s)\n' "$test_name" \
      "Failed due to build error" "$build_log"
    if [ -n "$selected_test" ]; then
      printf '\nBuild output:\n'
      cat "$build_log"
    fi
    build_failures=$((build_failures + 1))
    continue
  fi

  if [ ! -x "$executable" ]; then
    printf '%-36s %s (see %s)\n' "$test_name" \
      "Failed due to build error (missing executable)" "$build_log"
    if [ -n "$selected_test" ]; then
      printf '\nBuild output:\n'
      cat "$build_log"
    fi
    build_failures=$((build_failures + 1))
    continue
  fi

  if timeout --foreground "${test_timeout}s" "$runner" "$executable" \
      >"$run_log" 2>&1; then
    printf '%-36s %s\n' "$test_name" "Success"
    successes=$((successes + 1))
  else
    run_status=$?
    if [ "$run_status" -eq 124 ]; then
      result="Timed out after ${test_timeout}s"
    else
      result="Test failed"
    fi
    printf '%-36s %s (see %s)\n' "$test_name" "$result" "$run_log"
    if [ -n "$selected_test" ]; then
      printf '\nTest output:\n'
      cat "$run_log"
    fi
    test_failures=$((test_failures + 1))
  fi
done

if [ -z "$selected_test" ]; then
  printf '\nSuccess: %d\n' "$successes"
  printf 'Failed due to build error: %d\n' "$build_failures"
  printf 'Test failed: %d\n' "$test_failures"
fi

if [ "$build_failures" -ne 0 ] || [ "$test_failures" -ne 0 ]; then
  exit 1
fi
