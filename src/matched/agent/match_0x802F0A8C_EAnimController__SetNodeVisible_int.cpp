// 0x802F0A8C EAnimController::SetNodeVisible(int, (92 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mr. 4,4; bltlr; lwz 9,0x24(3); cmpwi 9,0; li 0,0; beq 0f; lwz 0,0x18(9); 0:; cmpw 4,0; bgelr; cmpwi 5,0; bne 1f; mulli 11,4,68; lwz 9,0xc(3); lwzx 0,11,9; ori 0,0,8; stwx 0,11,9; blr; 1:; mulli 11,4,68; lwz 9,0xc(3); lwzx 0,11,9; rlwinm 0,0,0,29,27; stwx 0,11,9"
extern "C" void f_802F0A8C() {}
