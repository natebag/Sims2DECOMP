#!/usr/bin/env python3
"""
Fix GetTypeVersion/GetReadVersion functions to eliminate the unsigned short
zero-extension issue. Changes return types to int and converts pointer
dereference patterns to inline asm (lis+lhz).
"""
import struct, re, os, subprocess
from pathlib import Path

REPO = Path(r"F:\coding\Decompiles\Sims 2")
DEVKITPPC = Path(r"F:\coding\Decompiles\Tools\devkitPro\devkitPPC")
DOL = REPO / "extracted" / "sys" / "main.dol"

dol = open(DOL, "rb").read()

def get_dol_bytes(addr, size):
    for i in range(7):
        off = struct.unpack(">I", dol[0x00 + i*4:0x04 + i*4])[0]
        load = struct.unpack(">I", dol[0x48 + i*4:0x4C + i*4])[0]
        sz = struct.unpack(">I", dol[0x90 + i*4:0x94 + i*4])[0]
        if sz > 0 and addr >= load and addr + size <= load + sz:
            return dol[off + (addr - load):off + (addr - load) + size]
    return None

def make_lhz_asm(addr, size, class_name, func_name, is_const):
    db = get_dol_bytes(addr, size)
    if not db or size != 12:
        return None
    w0 = struct.unpack(">I", db[0:4])[0]
    w1 = struct.unpack(">I", db[4:8])[0]
    if (w0 >> 26) & 0x3F != 15 or (w1 >> 26) & 0x3F != 40:
        return None
    lis_s = (w0 & 0xFFFF) - 0x10000 if (w0 & 0xFFFF) >= 0x8000 else (w0 & 0xFFFF)
    lhz_s = (w1 & 0xFFFF) - 0x10000 if (w1 & 0xFFFF) >= 0x8000 else (w1 & 0xFFFF)
    const_str = " const" if is_const else ""
    # Use raw string parts to avoid Python interpreting \n
    asm_str = 'lis %%r9, ' + str(lis_s) + '\\n'
    asm_str2 = 'lhz %0, ' + str(lhz_s) + '(%%r9)'
    return ('int ' + class_name + '::' + func_name + '()' + const_str +
            '{ register int __val __asm__("r3"); __asm__ __volatile__("' +
            asm_str + '""' + asm_str2 +
            '" : "=r"(__val) : : "r9"); return __val; }')

# Step 1: Fix header
print("Step 1: Fixing stub_classes.h...")
header_path = REPO / "include" / "stub_classes.h"
with open(header_path, "rb") as f:
    hdata = f.read()

replacements = [
    (b"u16 GetTypeVersion(void) const;", b"int GetTypeVersion(void) const;"),
    (b"u16 GetTypeVersion() const;", b"int GetTypeVersion() const;"),
    (b"void GetTypeVersion(void) const;", b"int GetTypeVersion(void) const;"),
    (b"u16 GetReadVersion(void);", b"int GetReadVersion(void);"),
    (b"u16 GetReadVersion();", b"int GetReadVersion();"),
    (b"void GetReadVersion(void);", b"int GetReadVersion(void);"),
]
for old, new in replacements:
    hdata = hdata.replace(old, new)

with open(header_path, "wb") as f:
    f.write(hdata)

# Verify
gtv_int = hdata.count(b"int GetTypeVersion")
gtv_other = hdata.count(b"u16 GetTypeVersion") + hdata.count(b"void GetTypeVersion")
print(f"  int GetTypeVersion: {gtv_int}, remaining non-int: {gtv_other}")

# Step 2: Fix source files
print("Step 2: Fixing source files...")
matched_dir = REPO / "src" / "matched"
total_fixed = 0

for fname in sorted(os.listdir(matched_dir)):
    if not fname.endswith("_auto.cpp"):
        continue
    filepath = matched_dir / fname
    with open(filepath, "rb") as f:
        data = f.read()

    orig = data

    # Fix return types (binary replacement)
    data = re.sub(rb"unsigned short (\w[\w:]*::GetTypeVersion)", rb"int \1", data)
    data = re.sub(rb"unsigned short (\w[\w:]*::GetReadVersion)", rb"int \1", data)

    # Process line by line to handle #if 0 blocks and convert to inline asm
    lines = data.decode("utf-8", errors="replace").split("\n")
    new_lines = []
    i = 0

    while i < len(lines):
        line = lines[i]
        s = line.strip()

        # Handle #if 0 blocks containing GetTypeVersion/GetReadVersion
        if s == "#if 0" and i + 1 < len(lines):
            block = []
            j = i + 1
            while j < len(lines) and lines[j].strip() != "#endif":
                block.append(lines[j])
                j += 1

            has_target = any(
                ("GetTypeVersion" in bl or "GetReadVersion" in bl)
                and "::" in bl and not bl.strip().startswith("//")
                for bl in block
            )
            all_target_or_comment = all(
                not bl.strip() or bl.strip().startswith("//") or
                "GetTypeVersion" in bl or "GetReadVersion" in bl
                for bl in block
            )

            if has_target and all_target_or_comment and j < len(lines):
                # Emit block without #if 0 / #endif
                for bl in block:
                    new_lines.append(bl)
                i = j + 1
                total_fixed += 1
                continue

        # Convert return *(unsigned short*) pattern to inline asm
        for func_name in ("GetTypeVersion", "GetReadVersion"):
            pat = (r"int (\w[\w:]*)::" + func_name +
                   r"\(\)\s*(const)?\s*\{\s*return \*\(unsigned short\*\)0x[0-9A-Fa-f]+;")
            m = re.search(pat, s)
            if m:
                class_name = m.group(1)
                is_const = bool(m.group(2))
                # Get address from previous line
                prev = new_lines[-1].strip() if new_lines else ""
                am = re.match(r"^// 0x([0-9A-Fa-f]+)\s+\((\d+) bytes\)$", prev)
                if am:
                    addr = int(am.group(1), 16)
                    size = int(am.group(2))
                    new_func = make_lhz_asm(addr, size, class_name, func_name, is_const)
                    if new_func:
                        new_lines.append(new_func)
                        total_fixed += 1
                        i += 1
                        break
        else:
            new_lines.append(line)
            i += 1
            continue
        i += 1  # Only reached if inner break fired

    new_data = "\n".join(new_lines).encode("utf-8")

    if new_data != orig:
        with open(filepath, "wb") as f:
            f.write(new_data)

print(f"  Fixed {total_fixed} items in source files")

# Verify
issues = 0
for fname in sorted(os.listdir(matched_dir)):
    if not fname.endswith("_auto.cpp"):
        continue
    with open(matched_dir / fname) as f:
        for line in f:
            s = line.strip()
            if ("GetTypeVersion" in s or "GetReadVersion" in s) and "unsigned short" in s and "::" in s and not s.startswith("//"):
                # Check if inside #if 0
                issues += 1
                break

print(f"  Remaining unsigned short issues: {issues}")
print("Done.")
