import os, re, sys

matched_dir = 'src/matched'
results = []

min_b = int(sys.argv[1]) if len(sys.argv) > 1 else 52
max_b = int(sys.argv[2]) if len(sys.argv) > 2 else 80

for root, dirs, files in os.walk(matched_dir):
    for fn in files:
        if not fn.endswith('.cpp'):
            continue
        path = os.path.join(root, fn)
        try:
            with open(path, encoding='utf-8', errors='ignore') as f:
                content = f.read()
        except:
            continue

        if 'ASMPROC_inject_before' not in content:
            continue

        # Extract size from first line comment
        m = re.search(r'//.*?\((\d+) B\)', content[:200])
        if not m:
            continue
        size = int(m.group(1))
        if size < min_b or size > max_b:
            continue

        # Extract address from filename
        am = re.search(r'0x([0-9A-Fa-f]{8})', fn)
        if not am:
            continue
        addr = int(am.group(1), 16)

        # Game code range: < 0x80240000 or >= 0x802E0000 (EA game code, not SDK)
        if addr >= 0x80240000 and addr < 0x802E0000:
            continue

        # Extract inject lines
        inject_match = re.search(r'ASMPROC_inject_before.*?lines="([^"]+)"', content)
        bl_count = 0
        inject_lines = ''
        has_internal_blr = False
        if inject_match:
            inject_lines = inject_match.group(1)
            bl_count = inject_lines.count(' bl ')
            # check for blrl, bctrl, blr, and conditional blr forms
            has_internal_blr = bool(re.search(r'\bblrl\b|\bbctrl\b|\bblr\b|\bblrl\b|\bbnelr\b|\bbeqlr\b|\bbltlr\b|\bblelr\b|\bbgtlr\b|\bbgelr\b', inject_lines))

        results.append((size, bl_count, has_internal_blr, addr, path, inject_lines))

results.sort()
for size, bl_count, has_blr, addr, path, inject_lines in results[:120]:
    blr_flag = 'BLR' if has_blr else '   '
    print(f'{size:3d}B bl={bl_count} {blr_flag} 0x{addr:08X} {os.path.basename(path)[:60]}')
    if '--verbose' in sys.argv:
        print(f'    {inject_lines[:120]}')
