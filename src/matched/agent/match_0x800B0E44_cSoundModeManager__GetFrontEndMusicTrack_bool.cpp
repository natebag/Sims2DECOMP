// 0x800B0E44 cSoundModeManager::GetFrontEndMusicTrack(bool) (44 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="cmpwi 4,0; bne 0f; lis 9,-32702; lwz 3,0x401c(9); blr; 0:; lwz 0,0x28(3); lis 9,-32702; addi 9,9,16412; rlwinm 0,0,2,0,29; lwzx 3,9,0"
extern "C" int f_800B0E44() {}
