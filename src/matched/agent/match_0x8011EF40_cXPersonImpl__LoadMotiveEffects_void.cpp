// 0x8011EF40 cXPersonImpl::LoadMotiveEffects(void) (300 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-64(1); mfspr 0,8; stmw 29,0x34(1); stw 0,0x44(1); mr 30,3; lwz 9,0x0(30); lwz 10,0x4(9); lwz 11,0x4(10); lwz 0,0x314(11); lha 3,0x310(11); mtspr 8,0; add 3,10,3; blrl; lha 0,0x66(3); cmpwi 0,0; beq 0f; lwz 11,0x0(30); lwz 29,0x408(30); lwz 10,0x4(11); lwz 9,0x4(10); lwz 0,0x37c(9); lha 3,0x378(9); mtspr 8,0; add 3,10,3; blrl; bl _s8011EF40_0; lwz 11,0x0(30); mr 30,3; lwz 10,0x4(11); lwz 9,0x4(10); lha 3,0x310(9); lwz 0,0x314(9); add 3,10,3; mtspr 8,0; blrl; lha 5,0x66(3); mr 4,30; mr 3,29; bl _s8011EF40_1; b 2f; 0:; lis 9,-32706; addi 11,1,8; addi 9,9,-13252; li 10,24; 1:; lwz 0,0x0(9); addic. 10,10,-24; stw 0,0x0(11); lwz 0,0x4(9); stw 0,0x4(11); lwz 0,0x8(9); stw 0,0x8(11); lwz 0,0xc(9); stw 0,0xc(11); lwz 0,0x10(9); stw 0,0x10(11); lwz 0,0x14(9); addi 9,9,24; stw 0,0x14(11); addi 11,11,24; bne 1b; lwz 0,0x0(9); addi 4,1,8; lwz 3,0x408(30); li 5,9; stw 0,0x0(11); lwz 0,0x4(9); stw 0,0x4(11); lwz 0,0x8(9); stw 0,0x8(11); bl _s8011EF40_2; 2:; lwz 0,0x44(1); mtspr 8,0; lmw 29,0x34(1); addi 1,1,64"
extern "C" void _s8011EF40_0();
extern "C" void _s8011EF40_1();
extern "C" void _s8011EF40_2();
extern "C" void f_8011EF40() {}
