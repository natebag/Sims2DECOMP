// 0x801747C0 CasSimState::HandleEventInitSim(CasEventInitSim (172 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="addi 4,4,8; addi 11,3,300; mr 9,4; li 10,288; 0:; lwz 0,0x0(9); addic. 10,10,-24; stw 0,0x0(11); lwz 0,0x4(9); stw 0,0x4(11); lwz 0,0x8(9); stw 0,0x8(11); lwz 0,0xc(9); stw 0,0xc(11); lwz 0,0x10(9); stw 0,0x10(11); lwz 0,0x14(9); addi 9,9,24; stw 0,0x14(11); addi 11,11,24; bne 0b; lwz 0,0x0(9); addi 3,3,8; li 9,288; stw 0,0x0(11); 1:; lwz 0,0x0(4); addic. 9,9,-24; stw 0,0x0(3); lwz 0,0x4(4); stw 0,0x4(3); lwz 0,0x8(4); stw 0,0x8(3); lwz 0,0xc(4); stw 0,0xc(3); lwz 0,0x10(4); stw 0,0x10(3); lwz 0,0x14(4); addi 4,4,24; stw 0,0x14(3); addi 3,3,24; bne 1b; lwz 0,0x0(4); stw 0,0x0(3)"
extern "C" void f_801747C0() {}
