from pathlib import Path
import re
from collections import defaultdict

claimed = {
    'targets_s2c', 'targets_tsc3', 'targets_cas', 'casmediator', 'caslistener', 
    'casevent', 'casclothing', 'invtarget',
    'iobject', 'object', 'objectsim', 'objectfolder', 'objectmodule',
    'cxperson', 'cxpersonimpl',
    'sanimator2', 'e_animcontroller', 'e_rlevel',
    'eroom', 'camera', 'xrouting',
}

class_to_dir = {
    'InteractorModule': 'interactormodule',
    'cXObjectImpl': 'cxobjectimpl',
    'AptDate': 'aptdate',
    'NeighborhoodImpl': 'neighborhoodimpl',
    'ERLevel': 'erlevel',
    'ObjectModuleImpl': 'objectmoduleimpl',
    'EAStringC': 'eastringc',
    'ObjectFolderImpl': 'objectfolderimpl',
    'cXPersonImpl': 'cxpersonimpl',
    'NghResFile': 'nghresfile',
    'IFFResFile2': 'iffresfile2',
    'Neighbor': 'neighbor',
    'RoomManager': 'roommanager',
    'AptArray': 'aptarray',
    'cXMTObjectImpl': 'cxmtobjectimpl',
    'EIStaticModel': 'eistaticmodel',
    'AptCIH': 'aptcih',
    'AptMathObj': 'aptmathobj',
    'AptActionInterpreter': 'aptactioninterpreter',
    'AptAnimationPoolData': 'aptanimationpooldata',
    'cHitMan': 'chitman',
    'ELightGrid': 'elightgrid',
    'ObjSelector': 'objselector',
    'ReconBuffer': 'reconbuffer',
    'SeqResFile': 'seqresfile',
    'EIStaticSubModel': 'eistaticsubmodel',
    'AptCharacterInst': 'aptcharacterinst',
    'AptString': 'aptstring',
    'cTrack': 'ctrack',
}

agent_dir = Path('src/matched/agent')
agent_stubs = {}
for f in agent_dir.glob('*.cpp'):
    try:
        with open(f, 'r', encoding='utf-8', errors='ignore') as fp:
            content = fp.read()
        if 'ASMPROC_inject_before' in content:
            m = re.search(r'(0x[0-9A-Fa-f]+)', f.name)
            if m:
                addr = m.group(1)
                agent_stubs[addr] = f.name
    except:
        pass

verify_dir = Path('build/verify')
verified = {}
for f in verify_dir.glob('*_clean.cpp'):
    m = re.search(r'(0x[0-9A-Fa-f]+)', f.name)
    if m:
        addr = m.group(1)
        if addr in agent_stubs:
            verified[addr] = (agent_stubs[addr], f.name)

categories = defaultdict(list)
for addr, (agent_name, verify_name) in verified.items():
    m = re.search(r'match_0x[0-9A-Fa-f]+_([^_]+)__', agent_name)
    if m:
        class_name = m.group(1)
    else:
        class_name = 'unknown'
    categories[class_name].append((addr, agent_name, verify_name))

print("# Agent Verified-Clean Pool Categorization")
print(f"\nTotal agent stubs with verified clean conversions: **{len(verified)}**\n")
print("| Class | Count | Semantic Dir | Claimed By | Status |")
print("|-------|-------|--------------|------------|--------|")

for class_name, items in sorted(categories.items(), key=lambda x: -len(x[1])):
    sem_dir = class_to_dir.get(class_name, '-')
    claimed_by = []
    for c in claimed:
        if class_name.lower() in c or c in class_name.lower():
            claimed_by.append(c)
    if sem_dir in claimed:
        claimed_by.append(sem_dir)
    status = "CLAIMED" if claimed_by else "UNCLAIMED"
    claimed_str = ', '.join(sorted(set(claimed_by))) if claimed_by else '-'
    print(f"| {class_name} | {len(items)} | {sem_dir} | {claimed_str} | {status} |")

print(f"\n## Top Unclaimed Classes (sorted by count)\n")
for class_name, items in sorted(categories.items(), key=lambda x: -len(x[1])):
    sem_dir = class_to_dir.get(class_name, '-')
    if sem_dir in claimed or any(c in class_name.lower() for c in claimed):
        continue
    print(f"### {class_name} ({len(items)} stubs)\n")
    for addr, agent_name, verify_name in sorted(items)[:5]:
        print(f"- {addr} -> {agent_name}")
    if len(items) > 5:
        print(f"- ... and {len(items)-5} more")
    print()
