#!/usr/bin/env python3
"""Corrected pool scout v2 — implements 3 fixes from pool-accuracy-correction."""
import os, re, struct, argparse

MAP_PATH = 'extracted/files/u2_ngc_release_dvd.map'
DOL_PATH = 'extracted/sys/main.dol'

# Build directories to exclude from matched file scan
BUILD_EXCLUDES = {'build', '__pycache__', '.git', '.pytest_cache', '.agentorch', '.cog', '.claude'}

# SDK zone
SDK_START = 0x80240000
SDK_END = 0x80390000

def parse_map(path):
    line_re = re.compile(r'^([0-9A-Fa-f]{8})\s+([0-9A-Fa-f]{8})\s+\d+\s+(.+?)\s*$')
    syms = []
    with open(path, 'r', errors='replace') as f:
        for line in f:
            m = line_re.match(line)
            if m:
                addr = int(m.group(1), 16)
                size = int(m.group(2), 16)
                name = m.group(3).strip()
                syms.append((addr, size, name))
    return syms

def collect_matched_project_wide():
    """Fix #1: Project-wide matched discovery with build-dir exclusions."""
    pat = re.compile(r'match_(0[xX])?([0-9A-Fa-f]{8})_')
    matched = set()
    for dirpath, _, filenames in os.walk('.'):
        # Skip build directories
        if any(excl in dirpath for excl in BUILD_EXCLUDES):
            continue
        for fn in filenames:
            if not fn.endswith('.cpp'):
                continue
            m = pat.match(fn)
            if m:
                matched.add(m.group(2).lower())
    return matched

def is_function_refined(name, size):
    """Fix #3: Refined function heuristic — broadens C/ctor detection
    while excluding C++ data members that lack parens in map."""
    if 'virtual table' in name:
        return False
    if name.startswith('.'):  # section names like .comment
        return False
    if name == '<default>' or name.startswith('<'):
        return False
    if '.sbss' in name or '.sdata' in name or '.bss' in name or '.data' in name:
        return False
    if '(' in name:
        return True
    if 'global constructors' in name or 'global destructors' in name:
        return True
    if '__static_initialization_and_destruction' in name:
        return True
    if name.startswith('_') and not name.startswith('__bss') and not name.startswith('__sbss'):
        return True
    
    # For C++ names without parens, be selective to exclude data members
    if '::' in name:
        base = name.split('::')[-1]
        # Exclude obvious data patterns
        if base.startswith('s_') or base.startswith('m_') or base.startswith('k'):
            return False
        if base.startswith('s') and len(base) > 1 and base[1].isupper():
            return False
        if base.startswith('m') and len(base) > 1 and base[1].isupper():
            return False
        # Exclude common data suffixes
        data_suffixes = ['Count', 'Size', 'Index', 'ID', 'Flag', 'Table', 'Array', 
                         'List', 'Map', 'Mutex', 'Params', 'Desc', 'Def', 'Cache', 
                         'Data', 'Info', 'Settings', 'Config']
        for suffix in data_suffixes:
            if base.endswith(suffix):
                return False
        # Exclude typeinfo
        if 'typeInfo' in base or 'TypeInfo' in base:
            return False
        return True
    
    return False

def read_dol():
    return open(DOL_PATH, 'rb').read()

def get_dol_bytes(addr, size, dol_data):
    for i in range(7):
        off = struct.unpack('>I', dol_data[0x00 + i*4:0x04 + i*4])[0]
        load = struct.unpack('>I', dol_data[0x48 + i*4:0x4C + i*4])[0]
        sz = struct.unpack('>I', dol_data[0x90 + i*4:0x94 + i*4])[0]
        if sz > 0 and addr >= load and addr + size <= load + sz:
            file_off = off + (addr - load)
            return dol_data[file_off:file_off + size]
    return None

def count_bl(insns):
    count = 0
    for w in insns:
        op = (w >> 26) & 0x3F
        if op == 18 and (w & 1):
            count += 1
    return count

def check_techniques_raw(bytes_data):
    flags = []
    insns = []
    for i in range(0, len(bytes_data), 4):
        word = int.from_bytes(bytes_data[i:i+4], 'big')
        insns.append(word)
    
    # cror-canonicalize
    for i in range(len(insns)):
        op = (insns[i] >> 26) & 0x3F
        if op == 11:
            if i+1 < len(insns):
                op2 = (insns[i+1] >> 26) & 0x3F
                if op2 == 19 and ((insns[i+1] >> 1) & 0x3FF) == 449:
                    flags.append('cror-canonicalize')
                    break
                if insns[i+1] == 0x7C000026:
                    if i+2 < len(insns):
                        op3 = (insns[i+2] >> 26) & 0x3F
                        if op3 == 21:
                            flags.append('cror-canonicalize')
                            break
    
    lwz_count = sum(1 for w in insns if ((w >> 26) & 0x3F) == 32)
    stw_count = sum(1 for w in insns if ((w >> 26) & 0x3F) == 36)
    if lwz_count >= 2 and stw_count >= 2:
        flags.append('load-pair-canonicalize')
    
    bl_count = count_bl(insns)
    if lwz_count >= 2 and stw_count >= 2 and bl_count == 0:
        flags.append('builtin-memcpy-pod?')
    
    has_beq = any(((w >> 26) & 0x3F) == 16 and ((w >> 16) & 0x3F) == 0x12 for w in insns)
    has_bne = any(((w >> 26) & 0x3F) == 16 and ((w >> 16) & 0x3F) == 0x0A for w in insns)
    if has_beq:
        flags.append('negated-test-fallthrough?')
    if has_bne:
        flags.append('mixed-eq-neq?')
    
    if stw_count >= 2:
        flags.append('volatile-store?')
    
    has_mr = any(((w >> 26) & 0x3F) == 31 and ((w >> 1) & 0x3FF) == 444 for w in insns)
    if has_mr:
        flags.append('goto-shared-exit-mr?')
    
    has_addi = any(((w >> 26) & 0x3F) == 14 for w in insns)
    if has_addi and bl_count >= 1 and len(insns) <= 20:
        flags.append('induction-var-walk?')
    
    return flags, bl_count

def main():
    parser = argparse.ArgumentParser()
    parser.add_argument('--include-sdk', action='store_true', help='Include SDK zone functions')
    parser.add_argument('--max-size', type=int, default=150, help='Max function size to include')
    parser.add_argument('--max-bl', type=int, default=2, help='Max bl calls to include')
    args = parser.parse_args()
    
    print('=' * 70)
    print('CORRECTED POOL V2 SCOUT')
    print(f'Filters: scope=project-wide, SDK={"included" if args.include_sdk else "excluded"}, '
          f'function-heuristic=broad, max-size={args.max_size}B, max-bl={args.max_bl}')
    print('=' * 70)
    print()
    
    syms = parse_map(MAP_PATH)
    matched = collect_matched_project_wide()
    dol_data = read_dol()
    
    print(f'Total symbols in DVD map: {len(syms):,}')
    print(f'Project-wide matched files: {len(matched):,}')
    print()
    
    # Build class data for near-complete TU analysis
    class_data = {}
    for addr, size, name in syms:
        if not is_function_refined(name, size):
            continue
        if not args.include_sdk and (SDK_START <= addr < SDK_END):
            continue
        cls = name.split('::')[0] if '::' in name else '(global)'
        if cls not in class_data:
            class_data[cls] = {'total': 0, 'matched': 0, 'items': []}
        class_data[cls]['total'] += 1
        addr_hex = f'{addr:08x}'
        is_matched = addr_hex in matched
        class_data[cls]['matched'] += 1 if is_matched else 0
        class_data[cls]['items'].append((addr, size, name, is_matched))
    
    # Near-complete TUs (>=80%)
    near_complete = []
    for cls, data in class_data.items():
        if data['total'] >= 10 and data['matched'] / data['total'] >= 0.80:
            remaining = [item for item in data['items'] if not item[3]]
            if remaining:
                near_complete.append((cls, data['matched'], data['total'], remaining))
    near_complete.sort(key=lambda x: (-x[1]/x[2], x[2]))
    
    # Simple-pattern pool
    simple_pool = []
    for addr, size, name in syms:
        if not is_function_refined(name, size):
            continue
        if not args.include_sdk and (SDK_START <= addr < SDK_END):
            continue
        if size > args.max_size:
            continue
        addr_hex = f'{addr:08x}'
        if addr_hex in matched:
            continue
        b = get_dol_bytes(addr, size, dol_data)
        if not b:
            continue
        techs, bl_count = check_techniques_raw(b)
        if bl_count > args.max_bl:
            continue
        tech_str = ', '.join(techs) if techs else '—'
        simple_pool.append((size, addr, name, tech_str, bl_count))
    
    simple_pool.sort()
    
    print(f'Near-complete TUs (>=80%, >=10 funcs): {len(near_complete)}')
    print(f'Simple-pattern pool (0-{args.max_bl} bl, <={args.max_size}B): {len(simple_pool)}')
    print()
    
    # Show top 30 simple-pattern candidates
    print('=== TOP 30 SIMPLE-PATTERN CANDIDATES (size-ascending) ===')
    print()
    for size, addr, name, tech_str, bl_count in simple_pool[:30]:
        print(f'0x{addr:08X}  {size:4d}B  bl={bl_count}  {name}  [{tech_str}]')
    print()
    
    # Show near-complete TU remaining functions
    print('=== NEAR-COMPLETE TU REMAINING FUNCTIONS ===')
    print()
    all_nc = []
    for cls, matched, total, remaining in near_complete:
        pct = matched / total * 100
        sub = [(addr, size, name) for addr, size, name, _ in remaining if size <= args.max_size]
        for addr, size, name in sub:
            b = get_dol_bytes(addr, size, dol_data)
            techs, bl_count = ([], -1) if not b else check_techniques_raw(b)
            tech_str = ', '.join(techs) if techs else '—'
            all_nc.append((size, addr, name, cls, tech_str, bl_count))
    
    all_nc.sort()
    for size, addr, name, cls, tech_str, bl_count in all_nc[:30]:
        bl_tag = f' bl={bl_count}' if bl_count >= 0 else ''
        print(f'0x{addr:08X}  {size:4d}B  {cls}  {name}  [{tech_str}]{bl_tag}')
    print()
    
    print(f'Total near-complete remaining (sub-{args.max_size}B): {len(all_nc)}')
    print(f'Total simple-pattern pool: {len(simple_pool)}')

if __name__ == '__main__':
    main()
