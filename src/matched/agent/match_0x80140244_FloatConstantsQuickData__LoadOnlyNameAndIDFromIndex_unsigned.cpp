// 0x80140244 FloatConstantsQuickData::LoadOnlyNameAndIDFromIndex(unsigned (8 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="addi 1,1,8"
extern "C" int f_80140244() {}
