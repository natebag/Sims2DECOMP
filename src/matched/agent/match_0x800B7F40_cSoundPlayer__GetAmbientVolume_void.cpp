// 0x800B7F40 cSoundPlayer::GetAmbientVolume(void) (20 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lis 9,-32697; lwz 11,0x5f14(9); lbz 3,0x29(11); extsb 3,3"
extern "C" int f_800B7F40() {}
