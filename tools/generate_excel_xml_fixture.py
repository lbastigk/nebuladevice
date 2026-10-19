#!/usr/bin/env python3
"""Generate the Excel XML fixture used by the legacy Foundation tests."""

from __future__ import annotations

import argparse
from pathlib import Path
from xml.etree import ElementTree


SS_NAMESPACE = "urn:schemas-microsoft-com:office:spreadsheet"


def worksheet(name: str, rows: list[list[str]]) -> ElementTree.Element:
    worksheet_element = ElementTree.Element("Worksheet", {"ss:Name": name})
    table = ElementTree.SubElement(worksheet_element, "Table")
    for row in rows:
        row_element = ElementTree.SubElement(table, "Row")
        for value in row:
            cell = ElementTree.SubElement(row_element, "Cell")
            data = ElementTree.SubElement(cell, "Data", {"ss:Type": "String"})
            data.text = value
    return worksheet_element


def build_fixture() -> ElementTree.ElementTree:
    workbook = ElementTree.Element(
        "Workbook",
        {
            "xmlns:o": "urn:schemas-microsoft-com:office:office",
            "xmlns:x": "urn:schemas-microsoft-com:office:excel",
            "xmlns:ss": SS_NAMESPACE,
        },
    )
    workbook.append(
        worksheet(
            "table0",
            [
                ["T0C0", "T0C1"],
                ["T0C0R1", "T0C1R1"],
                ["T0C0R2", "T0C1R2"],
            ],
        )
    )
    workbook.append(
        worksheet(
            "table1",
            [
                ["T1C0", "T1C1", "T1C2"],
                ["T1C0R1", "T1C1R1", "T1C2R1"],
                ["T1C0R2", "T1C1R2", "T1C2R2"],
                ["T1C0R3", "T1C1R3", "T1C2R3"],
                ["T1C0R4", "T1C1R4", "T1C2R4"],
            ],
        )
    )
    return ElementTree.ElementTree(workbook)


def main() -> int:
    parser = argparse.ArgumentParser()
    parser.add_argument("output", type=Path)
    args = parser.parse_args()

    args.output.parent.mkdir(parents=True, exist_ok=True)
    build_fixture().write(args.output, encoding="utf-8", xml_declaration=True)
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
