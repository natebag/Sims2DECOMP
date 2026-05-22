// 0x8022E260 TArray<int, (28 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 9,0x38(3); lwz 10,0x3c(3); stw 9,0x38(4); stw 10,0x3c(4); blr; lwz 3,0x110(3)"
extern "C" void f_8022E260() {}
