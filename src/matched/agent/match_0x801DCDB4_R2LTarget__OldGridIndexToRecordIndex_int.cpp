// 0x801DCDB4 R2LTarget::OldGridIndexToRecordIndex(int) (52 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mr 11,3; lwz 0,0xa8(11); mulli 9,0,6; cmpwi 0,0; add 3,4,9; blt 0f; cmpwi 3,0; blt 0f; lwz 0,0x9c(11); cmpw 3,0; bltlr; 0:; li 3,-1"
extern "C" int f_801DCDB4() {}
