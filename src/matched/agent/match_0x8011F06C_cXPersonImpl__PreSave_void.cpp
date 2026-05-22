// 0x8011F06C cXPersonImpl::PreSave(void) (80 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 30,3; lwz 3,0x0(30); bl _s8011F06C_0; lwz 11,-21476(13); lwz 4,0x4(30); lwz 9,0x0(11); lha 3,0xf0(9); lwz 0,0xf4(9); add 3,11,3; mtspr 8,0; blrl; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s8011F06C_0();
extern "C" void f_8011F06C() {}
