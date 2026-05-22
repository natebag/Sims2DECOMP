// 0x80069208 SAnimator2::IsDirectControlEnabled(void) (24 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 3,0x2c(3); addi 3,3,-9; subfic 3,3,5; li 3,0; adde 3,3,3"
extern "C" int f_80069208() {}
