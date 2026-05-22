// 0x8024AF7C PPCMtfpscr (40 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); stfd f31,0x18(1); li 4,0; stw 4,0x10(1); stw 3,0x14(1); lfd f31,0x10(1); .long 0xFDFEFD8E; lfd f31,0x18(1); addi 1,1,32"
extern "C" void f_8024AF7C() {}
