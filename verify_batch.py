import subprocess

addrs = [
    ('0x80205014', 'DirectInteractor_PreDraw'),
    ('0x80205040', 'DirectInteractor_Draw'),
    ('0x802079B8', 'FloorPainter_PreDraw'),
    ('0x802079E4', 'FloorPainter_Draw'),
    ('0x80219488', 'ObjectManipulator_PreDraw'),
    ('0x802194B4', 'ObjectManipulator_Draw'),
    ('0x8021E018', 'SimInteractor_PreDraw'),
    ('0x8021E044', 'SimInteractor_Draw'),
    ('0x8021F41C', 'SocialModeInteractor_PreDraw'),
    ('0x8021F448', 'SocialModeInteractor_Draw'),
]

for addr, name in addrs:
    dst = f'src/matched/agent/match_{addr}_InteractorModule__{name}.cpp'
    result = subprocess.run(['bash', 'tools/verify_match.sh', dst, addr, '44'], capture_output=True, text=True)
    ok = 'MATCH!' in result.stdout
    print(f'{addr} {name}: {"OK" if ok else "FAIL"}')
