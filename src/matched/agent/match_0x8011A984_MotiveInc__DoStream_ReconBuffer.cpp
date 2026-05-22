// 0x8011A984 MotiveInc::DoStream(ReconBuffer (92 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 29,3; mr 30,4; mr 3,30; mr 4,29; li 5,1; bl _s8011A984_0; mr 3,30; addi 4,29,4; li 5,1; bl _s8011A984_1; mr 3,30; addi 4,29,8; li 5,1; bl _s8011A984_2; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s8011A984_0();
extern "C" void _s8011A984_1();
extern "C" void _s8011A984_2();
extern "C" void f_8011A984() {}
