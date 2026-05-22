// 0x8013FCDC SetIndividualMemory(int (40 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="rlwinm 9,4,1,0,30; lwz 11,0x0(3); add 9,9,4; li 0,7; slw 0,0,9; slw 5,5,9; andc 0,11,0; or 0,0,5; stw 0,0x0(3)"
extern "C" void f_8013FCDC() {}
