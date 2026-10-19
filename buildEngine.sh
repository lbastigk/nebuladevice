#!/bin/bash
set -euo pipefail

cd "$(dirname "$0")"

architecture="${NEBULA_MINGW_ARCH:-64}"
case "$architecture" in
  32)
    toolchain="$PWD/cmake/mingw32-toolchain.cmake"
    build_dir="build-mingw32"
    build_option="-DNEBULA_BUILD_MINGW32=ON"
    ;;
  64)
    toolchain="$PWD/cmake/mingw64-toolchain.cmake"
    build_dir="build-mingw64"
    build_option="-DNEBULA_BUILD_MINGW64=ON"
    ;;
  *)
    printf 'Unsupported NEBULA_MINGW_ARCH: %s (expected 32 or 64)\n' "$architecture" >&2
    exit 2
    ;;
esac

cmake -S . \
  -B "$build_dir" \
  -DCMAKE_TOOLCHAIN_FILE="$toolchain" \
  "$build_option"

cmake --build "$build_dir" --parallel "${NEBULA_BUILD_JOBS:-2}"
