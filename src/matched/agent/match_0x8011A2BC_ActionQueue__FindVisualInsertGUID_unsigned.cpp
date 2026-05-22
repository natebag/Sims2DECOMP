// 0x8011A2BC ActionQueue::FindVisualInsertGUID(unsigned (160 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); mr 30,3; mr 29,4; lwz 0,0x2ac(30); lwz 9,0x2a8(30); subf 0,9,0; cmplw 29,0; bge 2f; lis 28,-13108; ori 28,28,52429; 0:; lwz 9,0x2a8(30); mr 3,30; add 9,9,29; mulhwu 0,9,28; rlwinm 0,0,29,3,31; mulli 0,0,10; subf 9,0,9; mulli 9,9,68; add 31,30,9; mr 4,31; bl _s8011A2BC_0; cmpwi 3,0; beq 1f; lwz 3,0x38(31); b 3f; 1:; lwz 9,0x2ac(30); addi 29,29,1; lwz 0,0x2a8(30); subf 9,0,9; cmplw 29,9; blt 0b; 2:; li 3,0; 3:; lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"
extern "C" void _s8011A2BC_0();
extern "C" void f_8011A2BC() {}
