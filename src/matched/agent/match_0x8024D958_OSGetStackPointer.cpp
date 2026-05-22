// 0x8024D958 OSGetStackPointer (8 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mr 3,1"
extern "C" int f_8024D958() {}
