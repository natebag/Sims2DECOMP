// 0x8011A06C ActionQueue::RemoveActionFromHUD(int) (124 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); lbz 0,0x2b0(3); cmpwi 0,0; bne 0f; lwz 0,0x2ac(3); lwz 9,0x2a8(3); subf 0,9,0; cmpw 4,0; bge 0f; lis 0,-13108; add 9,9,4; ori 0,0,52429; lis 11,-32697; mulhwu 0,9,0; lwz 11,0x5bcc(11); cmpwi 11,0; rlwinm 0,0,29,3,31; mulli 0,0,10; subf 9,0,9; mulli 9,9,68; add 5,3,9; beq 0f; lbz 4,0x2b1(3); mr 3,11; bl _s8011A06C_0; 0:; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s8011A06C_0();
extern "C" void f_8011A06C() {}
