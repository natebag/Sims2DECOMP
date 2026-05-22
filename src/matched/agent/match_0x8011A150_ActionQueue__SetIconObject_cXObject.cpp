// 0x8011A150 ActionQueue::SetIconObject(cXObject (192 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); mr 30,3; mr 29,5; lwz 9,0x2a8(30); mr 28,4; lwz 0,0x2ac(30); subf 0,9,0; cmplw 29,0; blt 0f; li 3,0; b 3f; 0:; lis 0,-13108; add 9,9,29; ori 0,0,52429; mulhwu 0,9,0; rlwinm 0,0,29,3,31; mulli 0,0,10; subf 9,0,9; mulli 9,9,68; add 31,30,9; mr 3,31; bl _s8011A150_0; cmpw 3,28; beq 2f; mr 4,28; mr 3,31; bl _s8011A150_1; mr 4,31; mr 3,30; bl _s8011A150_2; cmpwi 3,0; bne 1f; mr 3,30; mr 4,29; bl _s8011A150_3; b 2f; 1:; mr 3,30; mr 4,29; bl _s8011A150_4; 2:; li 3,1; 3:; lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"
extern "C" void _s8011A150_0();
extern "C" void _s8011A150_1();
extern "C" void _s8011A150_2();
extern "C" void _s8011A150_3();
extern "C" void _s8011A150_4();
extern "C" void f_8011A150() {}
