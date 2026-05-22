// 0x8024AF98 TArray<ENCameraPoint, (20 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lfd f31,0x18(1); addi 1,1,32; blr; mfspr 3,920"
extern "C" float f_8024AF98() {}
