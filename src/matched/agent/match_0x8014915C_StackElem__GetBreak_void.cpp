// 0x8014915C StackElem::GetBreak(void) (32 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lha 0,0x0(3); li 3,0; cmplwi 0,65535; beqlr; andi. 9,0,32768; beqlr; li 3,1"
extern "C" int f_8014915C() {}
