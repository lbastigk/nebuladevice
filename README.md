# Nebuladevice

This is a fork of Nebuladevice focused on running the engine on Linux through
Wine. The current work is focused on making the Windows Foundation layer run
reliably with MinGW-w64 and Wine. A native Linux port should follow once the
Wine-based compatibility layer is working.

## Source layout

- `_old/` - archived legacy files and documentation
- `external/` - bundled third-party sources and compatibility headers
- `include/Nebuladevice/` - engine headers
- `src/Nebuladevice/` - engine implementation sources
- `src/NebulaDeviceTests/` - migrated legacy test programs
- `tools/` - build-time fixture generators and utility scripts
- `work/` - generated test data and other build work files

## Native test build

The GoogleTest-based native test target is still work in progress:

```sh
cmake -S . -B build-tests \
  -DNEBULA_BUILD_TESTS=ON
cmake --build build-tests --target nebuladevice_tests
ctest --test-dir build-tests --output-on-failure
```

## MinGW Foundation build

The original game and engine use 32-bit Windows binaries. Configure and build
the Foundation layer with the matching toolchain:

```sh
cmake -S . -B build-mingw32 \
  -DCMAKE_TOOLCHAIN_FILE=cmake/mingw32-toolchain.cmake \
  -DNEBULA_BUILD_MINGW32=ON
cmake --build build-mingw32
```

The repository-local build helper selects the toolchain from
`NEBULA_MINGW_ARCH` (32 or 64, defaulting to 64):

```sh
./buildEngine.sh
NEBULA_MINGW_ARCH=32 ./buildEngine.sh
```

## Legacy test progress

The migrated legacy tests are discovered from `src/NebulaDeviceTests` and can
be built and run individually or as a suite with the repository-local
`buildLegacyTests.sh` helper.

Current status:

```text
  🟢 Success       2
  🟡 Won't build  29
  🔴 Failed        2
```

| Status | Count | Meaning |
| --- | ---: | --- |
| 🟢 Success | 2 | Builds and completes successfully |
| 🟡 Won't build | 29 | The legacy target does not currently compile or link |
| 🔴 Failed | 2 | Builds, but fails or times out while running |

This status is a progress snapshot, not a permanent test classification. As
targets are ported, move them between categories and update the counts above.
The runner uses a 120-second timeout for each test by default; override it
with `NEBULA_TEST_TIMEOUT_SECONDS`.

From the Nebuladevice repository:

```sh
./buildLegacyTests.sh
./buildLegacyTests.sh --list
./buildLegacyTests.sh testfoundation
NEBULA_TEST_TIMEOUT_SECONDS=300 ./buildLegacyTests.sh testfoundation
```

The legacy test build defines `NEBULA_NO_ERROR_DIALOGS`, so test failures do
not block the suite on a modal Windows error dialog. Errors still terminate
the failing process and are captured in the per-test log.

To enable Bash tab completion for the legacy test names, source
`buildLegacyTests.bash-completion` from your shell startup file.

## Generated Foundation fixtures

Foundation tests generate deterministic XML and BXML fixtures during the
legacy test build. The generators can also be run directly:

```sh
python3 tools/generate_bxml_fixture.py \
  build-legacy-mingw32/work/testdata/modelloadsavetest.bxml
python3 tools/generate_excel_xml_fixture.py \
  build-legacy-mingw32/export/testdata/excelxmlreadertest.xml
```

The old upstream Nebula3 SDK documentation is retained in `_old/` where
available. It describes the original Windows SDK and is not the authoritative
build documentation for this checkout.
