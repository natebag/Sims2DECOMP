// 0x8024D788 OSLoadFPUContext (8 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" replace="b f_8024D53C" lines="addi 4,3,0"
extern "C" void f_8024D53C();
extern "C" void f_8024D788() {}
