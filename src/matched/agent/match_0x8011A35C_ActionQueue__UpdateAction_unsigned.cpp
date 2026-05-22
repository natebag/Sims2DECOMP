// 0x8011A35C ActionQueue::UpdateAction(unsigned (156 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 31,3; mr 30,4; lwz 4,0x2a8(31); lwz 0,0x2ac(31); subf 0,4,0; cmplw 30,0; blt 0f; li 3,0; b 3f; 0:; lis 0,-13108; add 4,4,30; ori 0,0,52429; mr 3,31; mulhwu 0,4,0; rlwinm 0,0,29,3,31; mulli 0,0,10; subf 4,0,4; mulli 4,4,68; add 4,31,4; bl _s8011A35C_0; cmpwi 3,0; bne 1f; mr 3,31; mr 4,30; bl _s8011A35C_1; b 2f; 1:; mr 3,31; mr 4,30; bl _s8011A35C_2; 2:; li 3,1; 3:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s8011A35C_0();
extern "C" void _s8011A35C_1();
extern "C" void _s8011A35C_2();
extern "C" void f_8011A35C() {}
