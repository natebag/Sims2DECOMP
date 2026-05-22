// 0x8011089C ObjSelector::GetOriginal(void) (64 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); lwz 10,0x50(3); lwz 9,0x38(3); lwz 11,0x0(10); lwz 4,0x8c(9); lha 3,0x78(11); lwz 0,0x7c(11); add 3,10,3; mtspr 8,0; blrl; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void f_8011089C() {}
