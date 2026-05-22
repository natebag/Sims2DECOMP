// 0x801DCD68 R2LTarget::RecordIndexToGridIndex(int) (32 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 0,0xa4(3); li 3,-1; mulli 0,0,6; subf 4,0,4; cmpwi 4,6; bgtlr; mr 3,4"
extern "C" int f_801DCD68() {}
