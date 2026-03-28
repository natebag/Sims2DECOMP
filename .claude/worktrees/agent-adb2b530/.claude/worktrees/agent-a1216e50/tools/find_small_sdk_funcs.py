import re
import sys

with open('extracted/files/u2_ngc_release_dvd.map', 'r') as f:
    lines = f.readlines()

target_libs = ['os.a', 'exi.a', 'si.a', 'vi.a', 'pad.a', 'ai.a', 'dvd.a']
current_lib = None
current_obj = None
in_text_section = False
results_os = []
results_hw = []

BACKSLASH = chr(92)

for i, line in enumerate(lines):
    stripped = line.rstrip()

    # Detect section headers (e.g. "800034c0 003c7438    10 .text")
    m_sec = re.match(r'^([0-9a-fA-F]{8})\s+[0-9a-fA-F]+\s+\d+\s+(\.\w+)', stripped)
    if m_sec:
        sec_name = m_sec.group(2)
        if sec_name in ('.text', '.init'):
            in_text_section = True
        else:
            in_text_section = False
            current_lib = None
        continue

    # Detect file entries (deeply indented, contain path)
    if 'DolphinSDK' in stripped:
        for lib in target_libs:
            pat = lib + '('
            if pat in stripped:
                current_lib = lib
                mm = re.search(r'\(([^)]+)\)', stripped.split(lib)[1])
                if mm:
                    current_obj = mm.group(1)
                break
        else:
            # Not our target lib, reset
            current_lib = None
        continue

    # If we see another file that's NOT our target, reset
    if '.obj' in stripped:
        current_lib = None
        continue

    # Check for another .a( entry that's not ours
    if '.a(' in stripped and not any(lib + '(' in stripped for lib in target_libs):
        current_lib = None
        continue

    # Check for symbol entries
    if current_lib and in_text_section:
        # Symbol lines: "ADDR SIZE ALIGN SYMBOL_NAME"
        m = re.match(r'^([0-9a-fA-F]{8})\s+([0-9a-fA-F]{8})\s+\d+\s+(\S.+)$', stripped)
        if m:
            addr_s = m.group(1)
            size_s = m.group(2)
            name = m.group(3).strip()

            # Skip file entries (contain backslash or forward slash)
            if BACKSLASH in name or '/' in name:
                current_lib = None
                continue

            addr = int(addr_s, 16)
            size = int(size_s, 16)

            if size > 0 and size <= 0x40 and addr >= 0x80003100:
                entry = (addr, size, name, current_lib, current_obj)
                if current_lib == 'os.a':
                    results_os.append(entry)
                else:
                    results_hw.append(entry)

print('=== OS.A SMALL FUNCTIONS ===')
for addr, size, name, lib, obj in sorted(results_os, key=lambda x: x[0]):
    print(f'0x{addr:08X}  size=0x{size:02X} ({size:3d})  {obj:30s}  {name}')
print(f'\nTotal os.a: {len(results_os)}')

print('\n=== HW SMALL FUNCTIONS (exi/si/vi/pad/ai/dvd) ===')
for addr, size, name, lib, obj in sorted(results_hw, key=lambda x: x[0]):
    print(f'0x{addr:08X}  size=0x{size:02X} ({size:3d})  {lib}({obj:20s})  {name}')
print(f'\nTotal hw: {len(results_hw)}')
