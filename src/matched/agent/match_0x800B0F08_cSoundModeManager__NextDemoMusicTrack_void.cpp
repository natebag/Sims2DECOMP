// 0x800B0F08 cSoundModeManager::NextDemoMusicTrack(void) (32 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 9,0x2c(3); addi 9,9,1; cmplwi 9,2; stw 9,0x2c(3); blelr; li 0,1; stw 0,0x2c(3)"
extern "C" void f_800B0F08() {}
