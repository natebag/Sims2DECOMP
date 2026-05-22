// 0x801DCD88 R2LTarget::GridIndexToRecordIndex(int) (44 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 0,0xa4(3); mulli 0,0,6; add. 4,4,0; blt 0f; lwz 0,0x9c(3); cmpw 4,0; blt 1f; 0:; li 3,-1; blr; 1:; mr 3,4"
extern "C" int f_801DCD88() {}
