// 0x800B0E70 cSoundModeManager::NextFrontEndTrack(void) (32 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 9,0x28(3); addi 9,9,1; cmplwi 9,3; stw 9,0x28(3); blelr; li 0,0; stw 0,0x28(3)"
extern "C" void f_800B0E70() {}
