// 0x802B4D04 AptValueVector::PushValue(AptValue (56 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 10,0x4(3); lwz 0,0x0(3); cmpw 10,0; blt 0f; lwz 0,0x0(4); rlwinm 0,0,0,3,1; stw 0,0x0(4); blr; 0:; lwz 9,0x8(3); rlwinm 11,10,2,0,29; addi 0,10,1; stwx 4,11,9; stw 0,0x4(3)"
extern "C" void f_802B4D04() {}
