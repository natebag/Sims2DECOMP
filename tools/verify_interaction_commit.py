#!/usr/bin/env python3
import subprocess, os, re

BASH = r'F:\coding\Decompiles\Tools\devkitPro\msys2\usr\bin\bash.exe'

def verify(fpath):
    with open(fpath, 'r', errors='ignore') as f:
        content = f.read()
    m = re.search(r'0x([0-9a-fA-F]{8})', content)
    sm = re.search(r'\(\s*(\d+)\s*bytes?\s*\)', content, re.I)
    if not m:
        return None, None, None
    addr = '0x' + m.group(1)
    size = sm.group(1) if sm else '64'
    cmd = [BASH, '-lc', f'cd /f/coding/Decompiles/Sims\\ 2 && DEVKITPPC=/f/coding/Decompiles/Tools/devkitPro/devkitPPC ./tools/verify_match.sh "{fpath}" {addr} {size}']
    result = subprocess.run(cmd, capture_output=True, text=True, timeout=30)
    output = result.stdout + result.stderr
    if 'MATCH!' in output:
        return 'MATCH', addr, size
    elif 'SIZE_MISMATCH' in output or 'MISMATCH' in output:
        return 'MISMATCH', addr, size
    else:
        return 'ERROR', addr, size

files = [
'src/matched/interaction/match_0x800C189C_Interaction__SetUniqueID.cpp',
'src/matched/interaction/match_0x800C1960_Interaction__SetName_BString2.cpp',
'src/matched/interaction/match_0x800C1C74_Interaction__GetStackObject.cpp',
'src/matched/interaction/match_0x800C1C7C_Interaction__GetPerson.cpp',
'src/matched/interaction/match_0x800C1C84_Interaction__GetIconObject.cpp',
'src/matched/interaction/match_0x800C1C8C_Interaction__SetIconObject.cpp',
'src/matched/interaction/match_0x800C1D20_Interaction__GetTextColor.cpp',
'src/matched/interaction/match_0x800C1D44_Interaction__GetType.cpp',
'src/matched/interaction/match_0x800C1D4C_Interaction__GetAttenuation.cpp',
'src/matched/interaction/match_0x800C1D54_Interaction__GetTreeID.cpp',
'src/matched/interaction/match_0x800C1D5C_Interaction__GetStackVars.cpp',
'src/matched/interaction/match_0x800C1D64_Interaction__GetLocalVars.cpp',
'src/matched/interaction/match_0x800C1D6C_Interaction__GetLocalVarsCount.cpp',
'src/matched/interaction/match_0x800C1D74_Interaction__GetTreeTabEntryIndex.cpp',
'src/matched/interaction/match_0x800C1D7C_Interaction__GetPriority.cpp',
'src/matched/interaction/match_0x800C1D84_Interaction__SetPriority.cpp',
'src/matched/interaction/match_0x800C1D8C_Interaction__HasID.cpp',
'src/matched/interaction/match_0x800C1DA4_Interaction__GetID.cpp',
'src/matched/interaction/match_0x800C1DAC_Interaction__SetID.cpp',
'src/matched/interaction/match_0x800C1DB4_Interaction__GetAutoFirstSelect.cpp',
'src/matched/interaction/match_0x800C1E0C_Interaction__GetChecked.cpp',
'src/matched/interaction/match_0x800C1E38_Interaction__GetAvailable.cpp',
'src/matched/interaction/match_0x800C1E64_Interaction__GetHidden.cpp',
'src/matched/interaction/match_0x800C1E90_Interaction__GetPushToHead.cpp',
'src/matched/interaction/match_0x800C1EBC_Interaction__GetCarryNameOver.cpp',
'src/matched/interaction/match_0x800C1EE8_Interaction__GetNameChanged.cpp',
'src/matched/interaction/match_0x800C1F40_Interaction__GetDebugOverride.cpp',
'src/matched/interaction/match_0x800C1F6C_Interaction__GetMustRun.cpp',
'src/matched/interaction/match_0x800C1F98_Interaction__GetDisabled.cpp',
'src/matched/interaction/match_0x800C1FC4_Interaction__GetRunAsSub.cpp',
'src/matched/interaction/match_0x800C1FF0_Interaction__GetFlags.cpp',
'src/matched/interaction/match_0x800C1FF8_Interaction__SetFlags.cpp',
]

for f in files:
    status, addr, size = verify(f)
    print(f'{status}\t{addr}\t{size}\t{f}')
