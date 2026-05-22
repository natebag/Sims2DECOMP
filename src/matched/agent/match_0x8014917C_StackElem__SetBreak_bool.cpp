// 0x8014917C StackElem::SetBreak(bool) (48 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lhz 9,0x0(3); extsh 0,9; cmpwi 0,-1; beqlr; cmpwi 4,0; beq 0f; ori 0,9,32768; sth 0,0x0(3); blr; 0:; rlwinm 0,9,0,17,31; sth 0,0x0(3)"
extern "C" void f_8014917C() {}
