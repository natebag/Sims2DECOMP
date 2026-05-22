// 0x8011150C ObjSelector::GetShortFilename(StringBuffer (124 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-576(1); mfspr 0,8; stmw 27,0x22c(1); stw 0,0x244(1); addi 30,1,8; lwz 29,0x18(3); mr 27,4; li 5,260; addi 4,30,8; mr 3,30; bl _s8011150C_0; addi 28,1,280; mr 4,29; mr 3,30; li 5,-1; bl _s8011150C_1; addi 4,1,288; li 5,260; addi 3,1,280; bl _s8011150C_2; mr 3,30; mr 4,28; bl _s8011150C_3; mr 3,27; mr 4,28; bl _s8011150C_4; lwz 0,0x244(1); mtspr 8,0; lmw 27,0x22c(1); addi 1,1,576"
extern "C" void _s8011150C_0();
extern "C" void _s8011150C_1();
extern "C" void _s8011150C_2();
extern "C" void _s8011150C_3();
extern "C" void _s8011150C_4();
extern "C" void f_8011150C() {}
