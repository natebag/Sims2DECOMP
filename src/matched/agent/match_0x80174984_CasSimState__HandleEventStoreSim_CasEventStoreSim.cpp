// 0x80174984 CasSimState::HandleEventStoreSim(CasEventStoreSim (88 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="addi 9,3,8; li 11,288; addi 3,3,300; 0:; lwz 0,0x0(9); addic. 11,11,-24; stw 0,0x0(3); lwz 0,0x4(9); stw 0,0x4(3); lwz 0,0x8(9); stw 0,0x8(3); lwz 0,0xc(9); stw 0,0xc(3); lwz 0,0x10(9); stw 0,0x10(3); lwz 0,0x14(9); addi 9,9,24; stw 0,0x14(3); addi 3,3,24; bne 0b; lwz 0,0x0(9); stw 0,0x0(3)"
extern "C" void f_80174984() {}
