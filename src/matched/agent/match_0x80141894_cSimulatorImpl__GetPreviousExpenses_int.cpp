// 0x80141894 cSimulatorImpl::GetPreviousExpenses(int, (100 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="rlwinm 4,4,5,0,26; li 9,24; add 4,4,3; addi 4,4,180; 0:; lwz 0,0x0(4); addic. 9,9,-24; stw 0,0x0(5); lwz 0,0x4(4); stw 0,0x4(5); lwz 0,0x8(4); stw 0,0x8(5); lwz 0,0xc(4); stw 0,0xc(5); lwz 0,0x10(4); stw 0,0x10(5); lwz 0,0x14(4); addi 4,4,24; stw 0,0x14(5); addi 5,5,24; bne 0b; lwz 0,0x0(4); stw 0,0x0(5); lwz 0,0x4(4); stw 0,0x4(5)"
extern "C" void f_80141894() {}
