import os

for f in sorted(os.listdir('tools')):
    if f.startswith('all_') and f.endswith('_targets.txt'):
        path = os.path.join('tools', f)
        with open(path) as fp:
            content = fp.read()
        fam = content.count('FAMTarget')
        hud = content.count('HUDTarget')
        e2e = content.count('E2ETarget')
        if fam or hud or e2e:
            print(f"{f}: FAMTarget={fam}, HUDTarget={hud}, E2ETarget={e2e}")
