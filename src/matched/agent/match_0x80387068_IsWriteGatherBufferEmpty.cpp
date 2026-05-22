// 0x80387068 IsWriteGatherBufferEmpty (16 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="sync; mfspr 3,921; andi. 3,3,1"
extern "C" int f_80387068() {}
