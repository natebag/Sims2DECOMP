// 0x80030748 EIFenceWall::GetTypeInfoStatic(void) (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lis 3,-32688; addi 3,3,-19496"
extern "C" int f_80030748() {}
