// 0x8011ACFC ObjectRecord::DoStream(ReconBuffer (104 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); lwz 11,-21484(13); mr 29,3; mr 30,4; mr 5,29; lwz 9,0x0(11); lha 3,0x1d8(9); lwz 0,0x1dc(9); add 3,11,3; mtspr 8,0; blrl; mr 3,30; addi 4,29,4; li 5,1; bl _s8011ACFC_0; mr 3,30; addi 4,29,8; bl _s8011ACFC_1; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s8011ACFC_0();
extern "C" void _s8011ACFC_1();
extern "C" void f_8011ACFC() {}
