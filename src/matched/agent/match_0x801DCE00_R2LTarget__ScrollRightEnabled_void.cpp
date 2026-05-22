// 0x801DCE00 R2LTarget::ScrollRightEnabled(void) (40 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mr 9,3; lwz 11,0xa4(9); li 3,1; lwz 0,0x9c(9); addi 11,11,1; mulli 11,11,6; subf 9,11,0; bgtlr; li 3,0"
extern "C" int f_801DCE00() {}
