import os, re, json

# Keywords for Build mode / UI / Inventory
keywords = [
    'InteractorModule', 'TileWalls', 'RoutingSlot', 'SpriteSlot',
    'HUDTarget', 'ActionMenu', 'EyeToyClient', 'cXObjectImpl',
    'BitArray64', 'CDirtyXmlNode', 'FadeSquare', 'InteractionHelper',
    'LoadingScreenStateMachine', 'M2MTarget', 'MUStatesSaveNewGame',
    'R2LTarget', 'UIHDTV', 'ChangeHouseLoadHouse', 'LiveModeInitState',
    'ELiveMode', 'ObjDefinition', 'ObjectModuleImpl', 'EInstance'
]

map_path = 'extracted/files/u2_ngc_release_dvd.map'
pattern = re.compile(r'^([0-9a-fA-F]{8})\s+([0-9a-fA-F]{8})\s+\d+\s+(.*)$')

funcs = []
with open(map_path, 'r') as f:
    for line in f:
        m = pattern.match(line)
        if m:
            addr, size, name = m.groups()
            size_val = int(size, 16)
            addr_val = int(addr, 16)
            if size_val in (24, 28, 32):
                if 0x80240000 <= addr_val <= 0x80390000:
                    continue
                name = name.strip()
                if any(k in name for k in keywords):
                    funcs.append((addr_val, size_val, name))

matched = set()
for root, dirs, files in os.walk('src/matched'):
    for f in files:
        m = re.search(r'0x([0-9a-fA-F]{8})', f)
        if m:
            matched.add(int(m.group(1), 16))

unmatched = [(a, s, n) for a, s, n in funcs if a not in matched]
print(f"Unmatched Build/UI/Inventory 24-32B functions: {len(unmatched)}")
for a, s, n in unmatched:
    print(f"0x{a:08X}  {s}B  {n}")
