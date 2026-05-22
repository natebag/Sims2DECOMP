// 0x800EC684 ObjectFolderImpl::ObjectFolderImpl(void) (456 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-112(1); mfspr 0,8; stmw 24,0x50(1); stw 0,0x74(1); lis 9,-32698; lis 11,-32698; mr 30,3; addi 9,9,6296; addi 11,11,6272; stw 9,0x0(30); stw 11,0x4(30); addi 3,30,8; bl _s800EC684_0; li 29,0; lis 9,-32698; lis 11,-32698; lis 10,-32698; addi 9,9,5640; addi 10,10,5696; addi 11,11,5664; addi 28,30,24; stw 10,0x0(30); stw 9,0x4(30); li 3,24; stw 11,0x14(30); addi 27,30,40; stw 29,0x4(28); li 25,1; addi 26,30,1728; li 24,0; bl _s800EC684_1; mr 9,3; stw 29,0x8(28); stw 9,0x4(28); li 3,24; stb 29,0xc(28); stw 29,0x0(9); lwz 11,0x4(28); stw 29,0x4(11); lwz 9,0x4(28); stw 9,0x8(9); lwz 11,0x4(28); stw 11,0xc(11); stw 29,0x4(27); bl _s800EC684_2; stw 3,0x4(27); li 4,0; stw 29,0x8(27); li 5,1024; stb 29,0xc(27); stw 29,0x0(3); addi 3,30,64; lwz 11,0x4(27); stw 29,0x4(11); lwz 9,0x4(27); stw 9,0x8(9); lwz 11,0x4(27); stw 11,0xc(11); stw 29,0x38(30); stw 29,0x3c(30); bl _s800EC684_3; stw 29,0x440(30); addi 4,30,1100; li 5,260; addi 3,30,1092; bl _s800EC684_4; addi 4,30,1368; li 5,260; addi 3,30,1360; bl _s800EC684_5; stw 25,0x65c(30); addi 9,30,1632; stw 29,0x660(30); addi 11,30,1640; stw 29,0x4(9); addi 10,30,1648; stw 29,0x4(11); addi 9,30,1656; stw 29,0x670(30); addi 8,30,1664; stw 29,0x4(10); addi 11,30,1672; stw 29,0x4(9); li 0,-1; stw 29,0x680(30); addi 3,30,1692; stw 29,0x4(8); stw 29,0x4(11); stw 29,0x690(30); stw 29,0x694(30); stw 0,0x698(30); bl _s800EC684_6; sth 29,0x6bc(30); li 3,72; stw 29,0x4(26); bl _s800EC684_7; mr 9,3; stb 24,0xc(26); stw 9,0x4(26); mr 3,30; stw 29,0x8(26); stw 29,0x0(9); lwz 11,0x4(26); stw 29,0x4(11); lwz 9,0x4(26); stw 9,0x8(9); lwz 11,0x4(26); stw 11,0xc(11); stw 29,0x6d0(30); lwz 0,0x74(1); mtspr 8,0; lmw 24,0x50(1); addi 1,1,112"
extern "C" void _s800EC684_0();
extern "C" void _s800EC684_1();
extern "C" void _s800EC684_2();
extern "C" void _s800EC684_3();
extern "C" void _s800EC684_4();
extern "C" void _s800EC684_5();
extern "C" void _s800EC684_6();
extern "C" void _s800EC684_7();
extern "C" void f_800EC684() {}
