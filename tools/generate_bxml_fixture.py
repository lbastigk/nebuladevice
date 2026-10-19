#!/usr/bin/env python3
"""Generate the binary XML fixture used by the legacy Foundation tests."""

from __future__ import annotations

import argparse
import struct
from pathlib import Path


INVALID_NODE = 0xFFFF


def build_fixture() -> bytes:
    strings = [
        "Nebula3",
        "Model",
        "Attr",
        "Node",
        "name",
        "class",
        "parent",
        "ModelPos",
        "ModelInt",
        "ModelBool",
        "ModelString",
        "Node0",
        "Node1",
        "Node2",
        "Scene::ModelNode",
    ]
    string_indices = {value: index for index, value in enumerate(strings)}

    attrs = [
        ("name", "ModelPos"),
        ("name", "ModelInt"),
        ("name", "ModelBool"),
        ("name", "ModelString"),
        ("name", "Node0"),
        ("class", "Scene::ModelNode"),
        ("name", "Node1"),
        ("class", "Scene::ModelNode"),
        ("parent", "Node0"),
        ("name", "Node2"),
        ("class", "Scene::ModelNode"),
    ]
    packed_attrs = b"".join(
        struct.pack("<HH", string_indices[name], string_indices[value])
        for name, value in attrs
    )

    nodes = [
        # name, first child, next sibling, parent, first attr, attr count
        ("Nebula3", 1, INVALID_NODE, INVALID_NODE, 0, 0),
        ("Model", 2, INVALID_NODE, 0, 0, 0),
        ("Attr", INVALID_NODE, 3, 1, 0, 1),
        ("Attr", INVALID_NODE, 4, 1, 1, 1),
        ("Attr", INVALID_NODE, 5, 1, 2, 1),
        ("Attr", 6, 6, 1, 3, 1),
        ("Node", INVALID_NODE, 7, 1, 4, 2),
        ("Node", INVALID_NODE, 8, 1, 6, 3),
        ("Node", INVALID_NODE, INVALID_NODE, 1, 9, 2),
    ]
    packed_nodes = b"".join(
        struct.pack(
            "<HHHHII",
            string_indices[name],
            first_child,
            next_sibling,
            parent,
            first_attr,
            attr_count,
        )
        for name, first_child, next_sibling, parent, first_attr, attr_count in nodes
    )

    header = struct.pack(
        "<IIII",
        int.from_bytes(b"BXML", "big"),
        len(attrs),
        len(nodes),
        len(strings),
    )
    string_table = b"".join(value.encode("utf-8") + b"\0" for value in strings)
    return header + packed_attrs + packed_nodes + string_table


def main() -> int:
    parser = argparse.ArgumentParser()
    parser.add_argument("output", type=Path)
    args = parser.parse_args()

    args.output.parent.mkdir(parents=True, exist_ok=True)
    args.output.write_bytes(build_fixture())
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
