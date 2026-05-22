// 0x80184FE0 ActionQueueHUD::OnUserCancelledAction(unsigned (136 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 0,0x150(3); li 9,0; cmplw 9,0; bge 2f; mr 10,0; addi 11,3,168; 0:; lwz 0,0x0(11); addi 11,11,20; cmpw 0,4; bne 1f; mr 11,9; lwz 0,0x150(3); b 3f; 1:; addi 9,9,1; cmplw 9,10; blt 0b; 2:; lwz 11,0x150(3); mr 0,11; 3:; cmplw 11,0; bgelr; mulli 9,11,20; li 10,1; mr 11,9; add 9,9,3; lbz 0,0xad(9); cmpwi 0,0; bne 4f; li 10,0; 4:; cmpwi 10,0; bnelr; add 9,11,3; li 0,1; stb 0,0xad(9)"
extern "C" void f_80184FE0() {}
