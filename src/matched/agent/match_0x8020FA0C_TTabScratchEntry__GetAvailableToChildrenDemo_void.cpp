// 0x8020FA0C TTabScratchEntry::GetAvailableToChildrenDemo(void) (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" replace="b f_8020FA44" lines="stw 9,0x4(10); addi 10,10,8"
extern "C" void f_8020FA44();
extern "C" void f_8020FA0C() {}
