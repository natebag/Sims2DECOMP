import os, re, json

map_path = 'extracted/files/u2_ngc_release_dvd.map'
pattern = re.compile(r'^([0-9a-fA-F]{8})\s+([0-9a-fA-F]{8})\s+\d+\s+(.*)$')

# Systems claimed by others (exclude these)
claimed_systems = {
    'ESim', 'ESimsCam', 'cSimulatorImpl', 'cXPersonImpl', 'TheSimsStateMachine',
    'CreateASimBaseState', 'AptAction', 'AptCharacter', 'AptValue', 'FrameEffects',
    'REffects', 'EAnimController', 'SAnimator2', 'cXObject', 'ISimsObjectModel',
    'BBI', 'InteractorModule', 'SimsMemCardWrap', 'GoalUnlock', 'InventoryItem'
}

# My priority systems
my_systems = {
    'cSoundModeManager', 'AmbientScorePlayer', 'AmbientSoundPlayer',
    'SkinCompositor', 'Skin', 'LevelGen', 'Boot', 'ESimsApp', 'EGlobal',
    'EEngine', 'EHDTV', 'LiveMode', 'LoadingScreen', 'ChangeHouse',
    'BitArray', 'EyeToyClient', 'TileWalls', 'RoutingSlot', 'SpriteSlot',
    'HUDTarget', 'InteractionHelper', 'M2MTarget', 'R2LTarget', 'FadeSquare',
    'CDirtyXmlNode', 'ActionMenu', 'UIHDTV', 'ObjDefinition', 'ObjectModuleImpl',
    'cXObjectImpl', 'ERLevel', 'EResourceManager', 'XRoute', 'MUStates',
    'StaticGetShaderId'
}

funcs = []
with open(map_path, 'r') as f:
    for line in f:
        m = pattern.match(line)
        if m:
            addr, size, name = m.groups()
            size_val = int(size, 16)
            addr_val = int(addr, 16)
            if 40 <= size_val <= 64:
                if 0x80240000 <= addr_val <= 0x80390000:
                    continue
                name = name.strip()
                if 'virtual table' in name.lower() or 'vtable' in name.lower():
                    continue
                if name.endswith('.obj') or 'output\\obj' in name:
                    continue
                funcs.append((addr_val, size_val, name))

# Collect matched addrs - support both 0xAddress and Address formats
matched = set()
for root, dirs, files in os.walk('src/matched'):
    for f in files:
        m = re.search(r'0x([0-9a-fA-F]{8})', f)
        if m:
            matched.add(int(m.group(1), 16))
        m2 = re.search(r'(?<!0x)(?<!x)(^|_)([0-9a-fA-F]{8})(_|\.)', f)
        if m2:
            try:
                matched.add(int(m2.group(2), 16))
            except:
                pass

unmatched = [(a, s, n) for a, s, n in funcs if a not in matched]

# Heuristic to classify system from name
def classify(name):
    for sys in my_systems:
        if sys in name:
            return sys
    for sys in claimed_systems:
        if sys in name:
            return sys
    return 'Other'

# Group
groups = {}
for a, s, n in unmatched:
    sys = classify(n)
    if sys not in groups:
        groups[sys] = []
    groups[sys].append((a, s, n))

# Print my lane targets
print("=" * 60)
print("SESSION 6: 40-64B TARGETS — AUDIO / SKIN / MISC / UNCLAIMED")
print("=" * 60)
for sys in sorted(groups.keys()):
    funcs = groups[sys]
    claimed = "[CLAIMED]" if sys in claimed_systems else ""
    print(f"\n[{sys}] {claimed} — {len(funcs)} functions")
    for a, s, n in funcs[:20]:
        print(f"  0x{a:08X}  {s}B  {n}")
    if len(funcs) > 20:
        print(f"  ... and {len(funcs)-20} more")

print(f"\nTotal unmatched 40-64B: {len(unmatched)}")
