// 0x802F1F10 EGraphics::SetCensorRect(EVec3 (140 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 10,0x2a4(3); cmplwi 10,16; beqlr; rlwinm 10,10,2,0,29; addi 11,3,164; li 0,1; addi 8,3,612; stwx 0,11,10; lwz 9,0x2a4(3); lwz 0,0x0(4); mulli 9,9,12; lwz 11,0x8(4); lwz 10,0x4(4); add 9,9,3; stw 0,0xe4(9); addi 9,9,228; stw 11,0x8(9); stw 10,0x4(9); lwz 11,0x2a4(3); lwz 0,0x0(5); mulli 11,11,12; lwz 9,0x8(5); lwz 10,0x4(5); add 11,11,3; stw 0,0x1a4(11); addi 11,11,420; stw 9,0x8(11); stw 10,0x4(11); lwz 0,0x2a4(3); rlwinm 0,0,2,0,29; stwx 6,8,0; lwz 9,0x2a4(3); addi 9,9,1; stw 9,0x2a4(3)"
extern "C" void f_802F1F10() {}
