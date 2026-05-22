// 0x8011EF88 BString::find(char (88 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" replace="b f_8011F058" lines="lwz 10,0x4(11); lwz 9,0x4(10); lwz 0,0x37c(9); lha 3,0x378(9); mtspr 8,0; add 3,10,3; blrl; bl _s8011EF88_0; lwz 11,0x0(30); mr 30,3; lwz 10,0x4(11); lwz 9,0x4(10); lha 3,0x310(9); lwz 0,0x314(9); add 3,10,3; mtspr 8,0; blrl; lha 5,0x66(3); mr 4,30; mr 3,29; bl _s8011EF88_1"
extern "C" void _s8011EF88_0();
extern "C" void _s8011EF88_1();
extern "C" void f_8011F058();
extern "C" void f_8011EF88() {}
