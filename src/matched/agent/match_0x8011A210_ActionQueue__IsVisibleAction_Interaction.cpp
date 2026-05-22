// 0x8011A210 ActionQueue::IsVisibleAction(Interaction (172 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 31,4; mr 30,3; mr 3,31; li 29,0; bl _s8011A210_0; cmpwi 3,0; beq 0f; lwz 0,0x3c(31); andi. 9,0,16; mfcr 29; rlwinm 29,29,3,31,31; 0:; cmpwi 29,0; beq 2f; lwz 0,0x3c(31); andi. 9,0,2; beq 2f; lwz 0,0x2ac(30); lwz 9,0x2a8(30); cmpw 0,9; bne 1f; li 3,0; b 3f; 1:; lis 0,-13108; ori 0,0,52429; mulhwu 0,9,0; rlwinm 0,0,29,3,31; mulli 0,0,10; subf 0,0,9; mulli 0,0,68; add 0,30,0; cmpw 31,0; beq 2f; li 29,0; 2:; mr 3,29; 3:; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s8011A210_0();
extern "C" void f_8011A210() {}
