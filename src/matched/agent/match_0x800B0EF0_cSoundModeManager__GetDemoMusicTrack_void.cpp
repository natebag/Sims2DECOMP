// 0x800B0EF0 cSoundModeManager::GetDemoMusicTrack(void) (24 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 0,0x2c(3); lis 9,-32702; addi 9,9,16412; rlwinm 0,0,2,0,29; lwzx 3,9,0"
extern "C" int f_800B0EF0() {}
