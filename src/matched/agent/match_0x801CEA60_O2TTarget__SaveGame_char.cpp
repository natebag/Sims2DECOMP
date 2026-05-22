// 0x801CEA60 O2TTarget::SaveGame(char (20 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="li 0,0; li 9,1; stw 0,0x250(3); stw 9,0x90(3)"
extern "C" void f_801CEA60() {}
