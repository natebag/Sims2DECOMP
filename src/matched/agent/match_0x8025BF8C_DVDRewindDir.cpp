// 0x8025BF8C DVDRewindDir (16 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 4,0x0(3); addi 0,4,1; stw 0,0x4(3)"
extern "C" void f_8025BF8C() {}
