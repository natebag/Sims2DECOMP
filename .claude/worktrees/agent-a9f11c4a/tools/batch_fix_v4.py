#!/usr/bin/env python3
"""
Batch fix v4: Fix inline asm register allocation issues.

The lis+lwz inline asm generates lwz r9,off(r9) instead of lwz r3,off(r9).
Fix: bind output to r3 explicitly and add r9 to clobber list.
"""

import re
from pathlib import Path

REPO = Path(r"F:\coding\Decompiles\Sims 2")


def fix_lis_lwz_asm(content):
    """Fix lis %%rN, X ; lwz %0, Y(%%rN) pattern to use register binding + clobber."""
    # Pattern: __asm__ __volatile__("lis %%rN, X\n""lwz %0, Y(%%rN)" : "=r"(__val));
    # Fix: register int __val __asm__("r3"); ... : "=r"(__val) : : "rN"

    # Match the lis+lwz pattern
    pattern = re.compile(
        r'(int|void\*) __val;\s*'
        r'__asm__ __volatile__\('
        r'"lis %%r(\d+), (-?\d+)\\n"'
        r'"(lwz|lhz|lbz) %0, (-?\d+)\(%%r\2\)"\s*'
        r':\s*"=r"\(__val\)\);'
    )

    def replace_match(m):
        ret_type = m.group(1)
        reg_num = m.group(2)
        lis_imm = m.group(3)
        load_op = m.group(4)
        load_off = m.group(5)

        # Use register binding for r3 and clobber for rN
        return (
            f'register int __val __asm__("r3"); '
            f'__asm__ __volatile__('
            f'"lis %%r{reg_num}, {lis_imm}\\n"'
            f'"{load_op} %0, {load_off}(%%r{reg_num})" '
            f': "=r"(__val) : : "r{reg_num}");'
        )

    new_content = pattern.sub(replace_match, content)
    return new_content


def fix_lis_addi_for_return(content):
    """Fix lis+addi pattern to ensure r3 is used for return values in 12-byte functions."""
    # These are already working for return values, no fix needed
    return content


def main():
    print("=" * 70)
    print("BATCH FIX V4 — Fix inline asm register allocation")
    print("=" * 70)

    matched_dir = REPO / "src" / "matched"
    total_fixed = 0

    for src_file in sorted(matched_dir.glob("*.cpp")):
        with open(src_file, "r") as f:
            content = f.read()

        new_content = fix_lis_lwz_asm(content)

        if new_content != content:
            # Count fixes
            import difflib
            old_lines = content.split("\n")
            new_lines = new_content.split("\n")
            diffs = 0
            for old, new in zip(old_lines, new_lines):
                if old != new:
                    diffs += 1

            with open(src_file, "w") as f:
                f.write(new_content)
            total_fixed += diffs
            print(f"  {src_file.name}: {diffs} fixes")

    print(f"\n  Total: {total_fixed} fixes")

    # Also fix the CasSceneGamecube SDA return that uses wrong register
    cas_file = matched_dir / "CasSceneGamecube_auto.cpp"
    if cas_file.exists():
        with open(cas_file, "r") as f:
            content = f.read()
        # Fix: the SDA return uses r9 instead of r3
        # Pattern: int __sda; __asm__ __volatile__("lwz %0, X(%%r13)" : "=r"(__sda));
        # The compiler may put __sda in r9 instead of r3
        # Fix: register int __sda __asm__("r3");
        old_sda = 'int __sda; __asm__ __volatile__("lwz %0, -31552(%%r13)" : "=r"(__sda));'
        new_sda = 'register int __sda __asm__("r3"); __asm__ __volatile__("lwz %0, -31552(%%r13)" : "=r"(__sda));'
        if old_sda in content:
            content = content.replace(old_sda, new_sda)
            with open(cas_file, "w") as f:
                f.write(content)
            total_fixed += 1
            print(f"  CasSceneGamecube_auto.cpp: 1 SDA fix")

    # Fix ALL SDA returns to use register binding
    for src_file in sorted(matched_dir.glob("*.cpp")):
        with open(src_file, "r") as f:
            content = f.read()

        # Pattern: int __sda; __asm__ __volatile__("lwz %0, X(%%r13)" : "=r"(__sda));
        sda_pattern = re.compile(
            r'int __sda;\s*__asm__ __volatile__\("lwz %0, (-?\d+)\(%%r13\)"\s*:\s*"=r"\(__sda\)\);'
        )
        def sda_replace(m):
            off = m.group(1)
            return f'register int __sda __asm__("r3"); __asm__ __volatile__("lwz %0, {off}(%%r13)" : "=r"(__sda));'

        new_content = sda_pattern.sub(sda_replace, content)
        if new_content != content:
            with open(src_file, "w") as f:
                f.write(new_content)
            print(f"  {src_file.name}: SDA r3 binding fix")
            total_fixed += 1

    print(f"\n  Grand total: {total_fixed}")
    print("=" * 70)


if __name__ == "__main__":
    main()
