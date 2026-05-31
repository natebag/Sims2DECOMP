#!/bin/sh
# Portable Python 3 launcher for the mixed WSL / Windows Git Bash fleet.
# Usage: bash tools/py3.sh <script.py> [args...]

try_python() {
    "$@" -c 'import sys; raise SystemExit(0 if sys.version_info[0] == 3 else 1)' >/dev/null 2>&1
}

if command -v python >/dev/null 2>&1 && try_python python; then
    exec python "$@"
fi

if command -v python3 >/dev/null 2>&1 && try_python python3; then
    exec python3 "$@"
fi

if command -v py >/dev/null 2>&1 && try_python py -3; then
    exec py -3 "$@"
fi

echo "ERROR: Python 3 not found. Tried: python, python3, py -3." >&2
exit 127
