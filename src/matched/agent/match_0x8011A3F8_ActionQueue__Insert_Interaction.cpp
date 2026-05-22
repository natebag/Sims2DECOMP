// 0x8011A3F8 ActionQueue::Insert(Interaction (320 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 27,0xc(1); stw 0,0x24(1); mr 29,3; mr 27,4; lwz 30,0x2ac(29); mr 28,5; lwz 11,0x2a8(29); subf 0,11,30; cmplwi 0,9; bgt 2f; mr 9,30; add 0,11,28; cmplw 9,0; ble 1f; lis 31,-13108; ori 31,31,52429; 0:; addi 30,9,-1; mulhwu 3,9,31; mulhwu 4,30,31; rlwinm 3,3,29,3,31; mulli 3,3,10; rlwinm 4,4,29,3,31; mulli 4,4,10; subf 3,3,9; mulli 3,3,68; subf 4,4,30; mulli 4,4,68; add 3,29,3; add 4,29,4; bl _s8011A3F8_0; lwz 0,0x2a8(29); mr 9,30; add 0,0,28; cmplw 9,0; bgt 0b; 1:; lis 3,-13108; mr 4,27; ori 3,3,52429; mulhwu 3,9,3; rlwinm 3,3,29,3,31; mulli 3,3,10; subf 3,3,9; mulli 3,3,68; add 3,29,3; bl _s8011A3F8_1; lwz 9,0x2ac(29); li 0,1; addi 9,9,1; stw 9,0x2ac(29); b 3f; 2:; li 0,0; 3:; cmpwi 0,0; bne 4f; li 3,0; b 6f; 4:; lwz 0,0x2a8(29); lis 9,-13108; ori 9,9,52429; add 0,0,28; mulhwu 9,0,9; rlwinm 9,9,29,3,31; mulli 9,9,10; subf 0,9,0; mulli 0,0,68; add 3,29,0; lwz 9,0x38(3); cmpwi 9,0; bne 5f; bl _s8011A3F8_2; 5:; mr 3,29; mr 4,28; bl _s8011A3F8_3; li 3,1; 6:; lwz 0,0x24(1); mtspr 8,0; lmw 27,0xc(1); addi 1,1,32"
extern "C" void _s8011A3F8_0();
extern "C" void _s8011A3F8_1();
extern "C" void _s8011A3F8_2();
extern "C" void _s8011A3F8_3();
extern "C" void f_8011A3F8() {}
