// 0x80199E5C CASSelectionTarget::ConvertGridIdxToOptionIdx(unsigned (20 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 3,0x548(3); rlwinm 3,3,2,0,29; addi 3,3,-8; add 3,4,3"
extern "C" int f_80199E5C() {}
