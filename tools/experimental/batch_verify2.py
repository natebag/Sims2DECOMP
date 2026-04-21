import subprocess, os

BASH = r'F:\coding\Decompiles\Tools\devkitPro\msys2\usr\bin\bash.exe'

files = [
    ('src/wip/version_diff/match_0x80096628_StateMachineManager__FindMachineById.cpp', '0x80096628', 64),
    ('src/wip/version_diff/match_0x80221394_WallManipulator_AdjustCursorPosition.cpp', '0x80221394', 44),
    ('src/wip/version_diff/match_0x80143438_SpriteSlot_ActivateForLoops.cpp', '0x80143438', 44),
    ('src/wip/version_diff/match_800C90B4_Neighbor__GetRelations.cpp', '0x800C90B4', 8),
    ('src/wip/version_diff/match_0x80119088_cSampleChannel_ctor.cpp', '0x80119088', 60),
    ('src/wip/version_diff/match_800D3BD0_NghResFile__Reopen.cpp', '0x800D3BD0', 8),
    ('src/wip/version_diff/match_0x8036A734_op_stream_REffectsEmitter.cpp', '0x8036A734', 64),
    ('src/wip/version_diff/match_0x8036A078_global_ctor.cpp', '0x8036A078', 44),
    ('src/wip/version_diff/match_80140DC8_cSimulatorImpl__HourTimeOfDayNextChanges.cpp', '0x80140DC8', 88),
    ('src/wip/version_diff/match_0x8030C71C_Add1Byte.cpp', '0x8030C71C', 36),
    ('src/wip/version_diff/match_0x8036AE30_op_file_REffectsSequencer.cpp', '0x8036AE30', 64),
    ('src/wip/version_diff/match_0x803698D0_passthru.cpp', '0x803698D0', 32),
    ('src/wip/version_diff/match_800D23C0__c2DArray__CopyTo_BString.cpp', '0x800D23C0', 60),
    ('src/wip/version_diff/match_800595B8_Player__GetPrimaryNeighbor.cpp', '0x800595B8', 164),
    ('src/wip/version_diff/match_0x801116a0_ObjSelector__GetNormalSimDescription.cpp', '0x801116a0', 72),
    ('src/wip/version_diff/match_0x8037E62C___DSPGetCurrentTask_8b.cpp', '0x8037E62C', 8),
    ('src/wip/version_diff/match_0x80108384_cXObjectImpl__TryParticleEffect.cpp', '0x80108384', 204),
    ('src/wip/version_diff/match_0x80118E84_cSamplePatch_dtor.cpp', '0x80118E84', 64),
]

matches = []
near_matches = []
no_matches = []

for fpath, addr, size in files:
    if not os.path.exists(fpath):
        print('MISSING: ' + fpath)
        continue
    result = subprocess.run([BASH, 'tools/verify_match.sh', fpath, addr, str(size)], capture_output=True, text=True)
    output = result.stdout + result.stderr
    if 'MATCH!' in output:
        print('MATCH: ' + addr + ' (' + str(size) + 'B)')
        matches.append((fpath, addr, size))
    elif 'NEAR_MATCH' in output:
        print('NEAR_MATCH: ' + addr + ' (' + str(size) + 'B)')
        near_matches.append((fpath, addr, size, output[-500:]))
    elif 'SIZE_MISMATCH' in output or 'MISMATCH' in output:
        print('MISMATCH: ' + addr + ' (' + str(size) + 'B)')
        near_matches.append((fpath, addr, size, output[-500:]))
    else:
        print('NO_MATCH/ERROR: ' + addr + ' (' + str(size) + 'B)')
        no_matches.append((fpath, addr, size, output[-500:]))

print('\n=== SUMMARY ===')
print('Matches: ' + str(len(matches)))
print('Near/Mismatches: ' + str(len(near_matches)))
print('No match/Error: ' + str(len(no_matches)))

for fpath, addr, size in matches:
    print('  MATCH ' + addr + ' (' + str(size) + 'B)')
