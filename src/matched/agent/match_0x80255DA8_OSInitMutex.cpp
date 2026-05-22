// 0x80255DA8 OSInitMutex (56 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-24(1); stw 31,0x14(1); mr 31,3; bl _s80255DA8_0; li 0,0; stw 0,0x8(31); stw 0,0xc(31); lwz 0,0x1c(1); lwz 31,0x14(1); addi 1,1,24; mtspr 8,0"
extern "C" void _s80255DA8_0();
extern "C" void f_80255DA8() {}
