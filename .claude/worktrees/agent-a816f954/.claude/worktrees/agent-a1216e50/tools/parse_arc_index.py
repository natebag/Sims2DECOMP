#!/usr/bin/env python3
"""Parse Sims 2 GC .arc index files (index.ind / index1.ind)

The index file maps resource IDs to offsets within .arc archive files.
Format is big-endian.
"""

import struct
import sys
import os

def read_u32(f):
    data = f.read(4)
    if len(data) < 4:
        return None
    return struct.unpack('>I', data)[0]

def parse_index(filepath):
    with open(filepath, 'rb') as f:
        data = f.read()

    size = len(data)
    print(f"Index file: {filepath} ({size} bytes)")
    print()

    # First, read the offset table at the start
    # It's pairs of (section_start, section_end) as big-endian u32
    pos = 0
    offset_pairs = []
    while pos < size:
        val = struct.unpack_from('>I', data, pos)[0]
        if val >= 0x100:  # First non-small offset = start of data
            break
        offset_pairs.append(val)
        pos += 4

    # Group into pairs
    sections = []
    for i in range(0, len(offset_pairs), 2):
        if i+1 < len(offset_pairs):
            sections.append((offset_pairs[i], offset_pairs[i+1]))

    print(f"Found {len(sections)} sections in offset table")
    print()

    # Parse each section
    for idx, (start, end) in enumerate(sections):
        if start >= size:
            break

        # Read category name at 'start'
        # Find null terminator
        name_end = data.index(b'\x00', start) if b'\x00' in data[start:start+64] else start+32
        name = data[start:name_end].decode('ascii', errors='replace')

        # After the name (aligned), read entry count and entries
        name_padded_end = name_end + 1
        while name_padded_end % 4 != 0:
            name_padded_end += 1

        if name_padded_end + 4 <= size:
            entry_count = struct.unpack_from('>I', data, name_padded_end)[0]
        else:
            entry_count = 0

        entry_data_start = name_padded_end + 4

        print(f"Section {idx}: '{name}'")
        print(f"  Offset: 0x{start:06X} - 0x{end:06X} ({end-start} bytes)")
        print(f"  Entry count: {entry_count}")

        if entry_count > 0 and entry_count < 10000:
            # Read first few entry IDs (4 bytes each)
            print(f"  First entries (hash IDs):")
            for j in range(min(entry_count, 5)):
                epos = entry_data_start + j * 4
                if epos + 4 <= size:
                    eid = struct.unpack_from('>I', data, epos)[0]
                    print(f"    [{j}] 0x{eid:08X}")

            if entry_count > 5:
                print(f"    ... ({entry_count - 5} more)")

            # After the ID table, there should be offset/size data
            id_table_end = entry_data_start + entry_count * 4
            if id_table_end + 8 <= size:
                # Check if there's an offset table after IDs
                first_offset = struct.unpack_from('>I', data, id_table_end)[0]
                second_val = struct.unpack_from('>I', data, id_table_end + 4)[0]
                print(f"  After IDs: 0x{first_offset:08X}, 0x{second_val:08X}")

        print()

def parse_arc_header(filepath):
    with open(filepath, 'rb') as f:
        data = f.read(min(256, os.path.getsize(filepath)))

    size = os.path.getsize(filepath)
    print(f"\nARC file: {filepath} ({size} bytes)")

    # Try both endiannesses for first 4 bytes
    val_be = struct.unpack_from('>I', data, 0)[0]
    val_le = struct.unpack_from('<I', data, 0)[0]

    # Bytes 4-7
    val2 = struct.unpack_from('>I', data, 4)[0]

    # Bytes 8-15 (timestamp)
    ts = struct.unpack_from('<Q', data, 8)[0]

    print(f"  Byte 0-3: 0x{val_be:08X} (BE) / 0x{val_le:08X} (LE)")
    print(f"  Byte 4-7: 0x{val2:08X} (version?)")
    print(f"  Byte 8-15: 0x{ts:016X} (timestamp?)")

    # After 16-byte header, look for type tag
    if size > 20:
        val_at_16 = struct.unpack_from('>I', data, 16)[0]
        tag_bytes = data[20:24]
        tag = tag_bytes.decode('ascii', errors='replace')
        print(f"  Byte 16-19: {val_at_16}")
        print(f"  Byte 20-23: '{tag}' (type tag)")

        if val_at_16 < 100:
            # Small number = could be tag length or entry count
            pass

        # Look for first filename
        sentinel = struct.unpack_from('>I', data, 24)[0]
        if sentinel == 0xFFFFFFFF:
            name_len = struct.unpack_from('>I', data, 28)[0]
            if name_len > 0 and name_len < 256:
                name = data[32:32+name_len-1].decode('ascii', errors='replace')
                print(f"  Sentinel: 0xFFFFFFFF")
                print(f"  First entry name ({name_len}): '{name}'")

if __name__ == '__main__':
    base = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
    data_dir = os.path.join(base, 'extracted', 'files', 'DATA')

    # Parse index files
    for idx_file in ['index.ind', 'index1.ind']:
        path = os.path.join(data_dir, idx_file)
        if os.path.exists(path):
            parse_index(path)
            print("=" * 60)

    # Parse a few .arc headers
    for arc_file in ['fonts.arc', 'textures.arc', 'shaders.arc', 'binaries.arc', 'levels.arc', 'effectss.arc']:
        path = os.path.join(data_dir, arc_file)
        if os.path.exists(path):
            parse_arc_header(path)
