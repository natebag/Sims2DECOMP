// 0x8031B8F8 ERQuickdata::Reload(EFile (80 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 30,3; mr 29,4; bl _s8031B8F8_0; lis 9,-32692; lwz 4,0x14(30); lwz 6,-17472(9); addi 5,30,24; mr 3,29; bl _s8031B8F8_1; mr 3,30; bl _s8031B8F8_2; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s8031B8F8_0();
extern "C" void _s8031B8F8_1();
extern "C" void _s8031B8F8_2();
extern "C" void f_8031B8F8() {}
