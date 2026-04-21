from pathlib import Path
import subprocess

tus = ['versioninfo', 'targets_tsc3', 'appmain', 'simulator', 'behaviorconstants', 'livemode', 'loadingscreenstate', 'behavior', 'gamesound']
for tu in tus:
    tu_dir = Path(f'src/matched/{tu}')
    total = len(list(tu_dir.glob('*.cpp')))
    tracked = sum(1 for f in tu_dir.glob('*.cpp') if subprocess.run(['git', 'ls-files', str(f)], capture_output=True, text=True).stdout.strip())
    print(f'{tu}: tu_dir={total}, tracked={tracked}, untracked={total-tracked}')

agent = Path('src/matched/agent')
print(f'Agent total: {len(list(agent.glob("*.cpp")))}')
