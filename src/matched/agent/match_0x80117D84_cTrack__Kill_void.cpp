// 0x80117D84 cTrack::Kill(void) (168 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); mr 30,3; li 29,0; stw 29,0x34(30); addi 28,30,28; bl _s80117D84_0; lis 9,-32706; li 4,0; lfs f1,-14916(9); mr 3,30; bl _s80117D84_1; mr 3,30; bl _s80117D84_2; mr 4,3; mr 3,28; bl _s80117D84_3; stw 29,0x18(30); mr 4,30; lwz 3,-24136(13); bl _s80117D84_4; lwz 3,-24136(13); mr 4,30; li 5,0; bl _s80117D84_5; addi 3,30,84; li 4,0; li 5,32; bl _s80117D84_6; stw 29,0x84(30); li 3,1; stw 29,0x80(30); stw 29,0x88(30); stw 29,0x8c(30); stw 29,0x90(30); lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"
extern "C" void _s80117D84_0();
extern "C" void _s80117D84_1();
extern "C" void _s80117D84_2();
extern "C" void _s80117D84_3();
extern "C" void _s80117D84_4();
extern "C" void _s80117D84_5();
extern "C" void _s80117D84_6();
extern "C" void f_80117D84() {}
