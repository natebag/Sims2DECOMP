#!/bin/sh
# Cross-shell entry point for tools/disasm_digest.py.
# Usage: bash tools/disasm_digest.sh <addr> <size>

SCRIPT_DIR=$(CDPATH= cd -- "$(dirname -- "$0")" && pwd)
exec sh "$SCRIPT_DIR/py3.sh" "$SCRIPT_DIR/disasm_digest.py" "$@"
