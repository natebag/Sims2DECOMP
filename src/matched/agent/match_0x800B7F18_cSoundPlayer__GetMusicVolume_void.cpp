// 0x800B7F18 cSoundPlayer::GetMusicVolume(void) (20 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lis 9,-32697; lwz 11,0x5f14(9); lbz 3,0x1d(11); extsb 3,3"
extern "C" int f_800B7F18() {}
