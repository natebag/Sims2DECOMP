import subprocess, os

BASH = r'F:\coding\Decompiles\Tools\devkitPro\msys2\usr\bin\bash.exe'

files = [
    ('src/wip/version_diff/match_0x8001E68C_CameraDirector__ForceDisableHud.cpp', '0x8001E68C', 44),
    ('src/wip/version_diff/match_800C1F14_Interaction__GetCancelled.cpp', '0x800C1F14', 12),
    ('src/wip/version_diff/match_0x80041B6C_EGlobal__EndSaveGame.cpp', '0x80041B6C', 48),
    ('src/wip/version_diff/match_800D3C20_NghResFile__CountTypes.cpp', '0x800D3C20', 8),
    ('src/wip/version_diff/match_800D25EC_LoadCacheFromMemoryCard.cpp', '0x800D25EC', 64),
    ('src/wip/version_diff/match_800D3BEC_NghResFile__GetFileName.cpp', '0x800D3BEC', 44),
    ('src/wip/version_diff/match_801490D0_TreeStack__GetNthFrame.cpp', '0x801490D0', 52),
    ('src/wip/version_diff/match_800BCB6C_IconGroupImpl__LoadStrings.cpp', '0x800BCB6C', 4),
    ('src/wip/version_diff/match_0x802AB5CC_AptRenderingContext__appendVertexMatrix_2.cpp', '0x802AB5CC', 72),
    ('src/wip/version_diff/match_800D1950_NeighborhoodImpl__SetHouseNum.cpp', '0x800D1950', 8),
    ('src/wip/version_diff/match_0x8036ADF0_op_stream_REffectsSequencer.cpp', '0x8036ADF0', 64),
    ('src/wip/version_diff/match_0x8036A024_ERSoundEvent__op_delete_void_ptr.cpp', '0x8036A024', 44),
    ('src/wip/version_diff/match_0x8036A6D4_ERSoundTrackData__GetProgramSize.cpp', '0x8036A6D4', 20),
    ('src/wip/version_diff/match_0x801069B4_cXObjectImpl__InventoryCommandParam_GetGuid.cpp', '0x801069B4', 116),
    ('src/wip/version_diff/match_0x8036B2A8_op_file_RParticle.cpp', '0x8036B2A8', 64),
    ('src/wip/version_diff/match_0x8036C184_li_wrapper.cpp', '0x8036C184', 36),
    ('src/wip/version_diff/match_800D3BD8_NghResFile__Close.cpp', '0x800D3BD8', 8),
    ('src/wip/version_diff/match_0x80118E84_cSamplePatch_dtor.cpp', '0x80118E84', 64),
    ('src/wip/version_diff/match_0x802EFD44_EAnimController__SetTrackSpeed.cpp', '0x802EFD44', 68),
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
