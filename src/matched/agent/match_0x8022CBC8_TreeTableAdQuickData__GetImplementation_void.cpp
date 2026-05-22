// 0x8022CBC8 TreeTableAdQuickData::GetImplementation(void) (8 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" replace="b f_8022CBE4" lines="mr 9,0"
extern "C" void f_8022CBE4();
extern "C" void f_8022CBC8() {}
