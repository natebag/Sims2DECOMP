// 0x8024AF5C PPCMffpscr (32 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); stfd f31,0x10(1); .long 0xFFE0048E; stfd f31,0x8(1); lwz 3,0xc(1); lfd f31,0x10(1); addi 1,1,24"
extern "C" void f_8024AF5C() {}
