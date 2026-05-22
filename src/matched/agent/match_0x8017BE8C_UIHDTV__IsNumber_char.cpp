// 0x8017BE8C UIHDTV::IsNumber(char) (20 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="addi 4,4,-48; subfic 3,4,9; li 3,0; adde 3,3,3"
extern "C" int f_8017BE8C() {}
