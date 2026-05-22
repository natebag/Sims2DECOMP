// 0x8024D790 OSSaveFPUContext (8 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" replace="b f_8024D660" lines="addi 5,3,0"
extern "C" void f_8024D660();
extern "C" void f_8024D790() {}
