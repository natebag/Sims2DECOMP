// 0x80149138 StackElem::SetTreeID(short) (36 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="cmpwi 4,-1; bne 0f; sth 4,0x0(3); blr; 0:; lhz 0,0x0(3); rlwinm 0,0,0,0,16; or 0,4,0; sth 0,0x0(3)"
extern "C" void f_80149138() {}
