// 0x800D39E4 NghResFile::NghResFile(void) (180 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 28,0x10(1); stw 0,0x24(1); mr 30,3; li 29,0; li 28,1; bl _s800D39E4_0; lis 9,-32698; addi 11,30,24; addi 9,9,2096; stw 29,0x10(30); stw 9,0xc(30); addi 4,30,48; stw 29,0x14(30); li 5,260; stw 29,0x4(11); addi 3,30,40; stw 28,0x20(30); stw 29,0x24(30); bl _s800D39E4_1; stw 28,0x18c(30); li 3,28; stb 29,0x134(30); stw 29,0x180(30); sth 29,0x184(30); stw 28,0x188(30); bl _s800D39E4_2; mr 9,3; stw 29,0x18(9); mr 3,30; stw 9,0x190(30); stw 29,0x0(9); stw 29,0x4(9); stw 29,0x8(9); stw 29,0xc(9); stw 29,0x10(9); stw 29,0x14(9); bl _s800D39E4_3; mr 3,30; lwz 0,0x24(1); mtspr 8,0; lmw 28,0x10(1); addi 1,1,32"
extern "C" void _s800D39E4_0();
extern "C" void _s800D39E4_1();
extern "C" void _s800D39E4_2();
extern "C" void _s800D39E4_3();
extern "C" void f_800D39E4() {}
