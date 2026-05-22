// 0x8017BF2C UIHDTV::IsFoundNumberNegative(char (24 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="add 5,5,4; lbz 3,-1(5); xoris 3,3,45; subfic 0,3,0; adde 3,0,3"
extern "C" int f_8017BF2C() {}
