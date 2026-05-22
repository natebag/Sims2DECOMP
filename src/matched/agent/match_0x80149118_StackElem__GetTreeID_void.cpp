// 0x80149118 StackElem::GetTreeID(void) (32 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lhz 3,0x0(3); extsh 0,3; cmpwi 0,-1; beq 0f; rlwinm 3,3,0,17,31; blr; 0:; li 3,-1"
extern "C" int f_80149118() {}
