#!/usr/bin/env python3
"""Extract resources from Sims 2 GC .arc archive files.

The .arc format (EA GameCube):
  Header (16 bytes):
    u32 LE: data_size (total data excluding header, approximately)
    u32 BE: version (always 0x00000100)
    u64 LE: timestamp (Windows FILETIME)

  Then a sequence of resource entries, each:
    u32 BE: type_tag_or_entry_info
    4 bytes: type tag ASCII (e.g., "TXFL", "FONT", "SHDR") or data
    u32 BE: 0xFFFFFFFF sentinel (or next field)
    u32 BE: name_length (including null)
    name_length bytes: null-terminated filename
    Then: raw resource data until next entry or EOF

  Some .arc files (like levels.arc) use a different entry format without
  the type tag + sentinel pattern.
"""

import struct
import os
import sys

def read_be_u32(data, offset):
    return struct.unpack_from('>I', data, offset)[0]

def read_le_u32(data, offset):
    return struct.unpack_from('<I', data, offset)[0]

def try_parse_arc(filepath):
    """Try to parse an .arc file and list its contents."""
    with open(filepath, 'rb') as f:
        data = f.read()

    size = len(data)
    name = os.path.basename(filepath)
    print(f"\n{'='*60}")
    print(f"Archive: {name} ({size:,} bytes)")
    print(f"{'='*60}")

    if size < 16:
        print("  Too small for header")
        return

    # Header
    data_size = read_le_u32(data, 0)
    version = read_be_u32(data, 4)
    timestamp = struct.unpack_from('<Q', data, 8)[0]

    print(f"  Data size: {data_size:,} (0x{data_size:08X})")
    print(f"  Version:   0x{version:08X}")
    print(f"  Timestamp: 0x{timestamp:016X}")

    if size <= 16:
        print("  (Empty archive)")
        return

    # Try to parse entries starting at offset 16
    pos = 16
    entry_count = 0
    entries = []

    while pos < size - 8:
        # Read potential entry header
        val1 = read_be_u32(data, pos)

        # Check if next 4 bytes look like an ASCII type tag
        tag_bytes = data[pos+4:pos+8]
        is_ascii_tag = all(32 <= b < 127 for b in tag_bytes) and len(tag_bytes) == 4

        if is_ascii_tag:
            tag = tag_bytes.decode('ascii')
            # Check for sentinel after tag
            if pos + 8 < size:
                sentinel = read_be_u32(data, pos+8)

            if sentinel == 0xFFFFFFFF and pos + 12 < size:
                # Tagged entry format: val1 | TAG | FFFFFFFF | name_len | name | data
                name_len = read_be_u32(data, pos+12)
                if name_len > 0 and name_len < 1024 and pos + 16 + name_len <= size:
                    entry_name = data[pos+16:pos+16+name_len-1].decode('ascii', errors='replace')
                    data_start = pos + 16 + name_len
                    # Align to 4
                    while data_start % 4 != 0:
                        data_start += 1

                    entries.append({
                        'offset': pos,
                        'tag': tag,
                        'name': entry_name,
                        'data_offset': data_start,
                        'header_val': val1,
                    })
                    entry_count += 1

                    # Try to find next entry by looking for next tag or EOF
                    # For now just scan forward
                    next_pos = data_start
                    # Look for next FFFFFFFF sentinel or end
                    found_next = False
                    scan_pos = data_start + 4
                    while scan_pos < size - 12:
                        if read_be_u32(data, scan_pos) == 0xFFFFFFFF:
                            # Check if 4 bytes before are ASCII tag
                            pre_tag = data[scan_pos-4:scan_pos]
                            if all(32 <= b < 127 for b in pre_tag):
                                # Found next entry, back up to start
                                next_entry_start = scan_pos - 8
                                if next_entry_start > data_start:
                                    entries[-1]['data_size'] = next_entry_start - data_start
                                    pos = next_entry_start
                                    found_next = True
                                    break
                        scan_pos += 4

                    if not found_next:
                        entries[-1]['data_size'] = size - data_start
                        break
                    continue

        # Non-tagged format (like levels.arc) - skip for now
        break

    print(f"\n  Found {entry_count} entries:")
    for i, e in enumerate(entries[:20]):
        ds = e.get('data_size', '?')
        print(f"    [{i:3d}] {e['tag']} | {e['name']:40s} | data@0x{e['data_offset']:08X} ({ds} bytes)")

    if len(entries) > 20:
        print(f"    ... ({len(entries) - 20} more)")

    return entries

if __name__ == '__main__':
    base = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
    data_dir = os.path.join(base, 'extracted', 'files', 'DATA')

    # Parse several .arc files
    for arc_file in sorted(os.listdir(data_dir)):
        if arc_file.endswith('.arc'):
            path = os.path.join(data_dir, arc_file)
            try:
                try_parse_arc(path)
            except Exception as e:
                print(f"  Error: {e}")
