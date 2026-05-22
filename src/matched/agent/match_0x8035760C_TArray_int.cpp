// 0x8035760C TArray<int, (28 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stw 7,0x3c(3); stw 8,0x4(9); stw 0,0x8(9); stw 10,0xc(9); lwz 0,0x10(11); stw 0,0x10(9)"
extern "C" void f_8035760C() {}
