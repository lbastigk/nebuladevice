#!/usr/bin/env python3
"""Generate the ZIP fixture used by the legacy ZIP test."""

from __future__ import annotations

import argparse
from pathlib import Path
from zipfile import ZIP_DEFLATED, ZipFile


def main() -> int:
    parser = argparse.ArgumentParser()
    parser.add_argument("output", type=Path)
    args = parser.parse_args()

    args.output.parent.mkdir(parents=True, exist_ok=True)
    with ZipFile(args.output, "w", compression=ZIP_DEFLATED) as archive:
        archive.writestr(
            "export_win32/shaders/shaders.dic",
            "shader fixture header\n"
            "shader fixture body\n",
        )
        archive.writestr("export_win32/test.txt", "zip fixture test\n")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
