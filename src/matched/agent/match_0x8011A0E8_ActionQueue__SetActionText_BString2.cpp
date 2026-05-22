// 0x8011A0E8 ActionQueue::SetActionText(BString2 (104 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); mr 9,3; lwz 3,0x2a8(9); lwz 0,0x2ac(9); subf 0,3,0; cmplw 5,0; bge 0f; lis 0,-13108; add 3,3,5; ori 0,0,52429; mulhwu 0,3,0; rlwinm 0,0,29,3,31; mulli 0,0,10; subf 3,0,3; mulli 3,3,68; add 3,9,3; bl _s8011A0E8_0; li 3,1; b 1f; 0:; li 3,0; 1:; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s8011A0E8_0();
extern "C" void f_8011A0E8() {}
