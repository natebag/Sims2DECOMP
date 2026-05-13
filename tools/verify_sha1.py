#!/usr/bin/env python3
"""Pure-Python SHA1 verifier — fallback for environments without sha1sum.

Reads a sha1sum-format file (one or more `<hex>  <path>` lines) and verifies
each file's SHA-1 matches. Exits 0 on success, 1 on mismatch or missing file.

Used by build.ninja's sha1_verify rule on Windows hosts that don't have
bash+coreutils available (devkitPro msys2 usually does, but build runners may
not). Matches the GNU coreutils sha1sum -c output format.
"""

import hashlib
import sys
from pathlib import Path


def main() -> int:
    if len(sys.argv) != 2:
        print("Usage: verify_sha1.py <checksums.sha1>", file=sys.stderr)
        return 2
    checksum_file = Path(sys.argv[1])
    if not checksum_file.is_file():
        print(f"verify_sha1.py: {checksum_file}: No such file", file=sys.stderr)
        return 1

    failed = 0
    checked = 0
    with open(checksum_file, encoding="utf-8") as f:
        for raw_line in f:
            line = raw_line.strip()
            if not line or line.startswith("#"):
                continue
            # sha1sum format: "<40-hex>  <path>" (two spaces) or "<40-hex> *<path>" (binary mode)
            parts = line.split(None, 1)
            if len(parts) != 2:
                continue
            expected, path_part = parts
            expected = expected.lower()
            if path_part.startswith("*"):
                path_part = path_part[1:]
            target = Path(path_part)
            if not target.is_file():
                print(f"{target}: FAILED open or read")
                failed += 1
                continue
            h = hashlib.sha1()
            with open(target, "rb") as t:
                while True:
                    chunk = t.read(1024 * 1024)
                    if not chunk:
                        break
                    h.update(chunk)
            actual = h.hexdigest()
            if actual == expected:
                print(f"{target}: OK")
                checked += 1
            else:
                print(f"{target}: FAILED  expected={expected} actual={actual}")
                failed += 1

    if failed:
        print(f"verify_sha1.py: WARNING: {failed} of {checked + failed} computed checksums did NOT match", file=sys.stderr)
        return 1
    return 0


if __name__ == "__main__":
    sys.exit(main())
