// 0x80313A38 FlashBigFile::CreateTexture(int) (444 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-112(1); mfspr 0,8; stmw 25,0x54(1); stw 0,0x74(1); mr 25,3; rlwinm 11,4,2,0,29; lwz 9,0x4(25); lis 3,-32692; stw 4,0x48(1); li 5,8; li 4,24; addi 3,3,-7364; lwzx 27,11,9; lwz 10,0x0(27); addi 11,27,4; mr 8,11; rlwinm 9,10,8,8,15; rlwinm 0,10,24,0,7; rlwinm 11,10,24,16,23; or 0,0,9; or 0,0,11; rlwinm 10,10,8,24,31; or 0,0,10; stw 0,0x0(27); lhz 9,0x10(8); lhz 0,0x12(8); rlwinm 10,9,8,16,23; lwz 6,0x8(8); rlwinm 11,0,8,16,23; rlwinm 9,9,24,8,31; rlwinm 0,0,24,8,31; or 10,10,9; or 11,11,0; sth 10,0x10(8); sth 11,0x12(8); rlwinm 0,6,8,8,15; rlwinm 9,6,24,0,7; lhz 30,0x10(8); lhz 11,0x12(8); or 9,9,0; lhz 7,0x14(8); rlwinm 0,6,24,16,23; lhz 10,0x16(8); mullw 30,30,11; or 9,9,0; rlwinm 11,7,8,16,23; rlwinm 0,10,8,16,23; rlwinm 6,6,8,24,31; rlwinm 7,7,24,8,31; rlwinm 10,10,24,8,31; or 11,11,7; or 9,9,6; or 0,0,10; sth 11,0x14(8); sth 0,0x16(8); add 11,27,30; stw 9,0x8(8); lwzu 0,0x424(11); lwz 9,0x4(11); rlwinm 10,0,8,8,15; rlwinm 28,0,24,0,7; rlwinm 8,0,24,16,23; rlwinm 11,9,8,8,15; rlwinm 29,9,24,0,7; or 28,28,10; or 29,29,11; rlwinm 10,9,24,16,23; or 28,28,8; or 29,29,10; rlwinm 0,0,8,24,31; rlwinm 9,9,8,24,31; or 28,28,0; or 29,29,9; bl _s80313A38_0; bl _s80313A38_1; mr 26,3; mr 3,25; bl _s80313A38_2; mr 30,3; addi 5,1,72; lwz 3,0x0(25); li 7,0; li 4,0; li 6,0; bl _s80313A38_3; mr 6,3; lis 4,-32702; mr 5,30; addi 3,1,8; addi 4,4,1552; crxor 6,6,6; bl _s80313A38_4; mr 4,27; mr 3,26; bl _s80313A38_5; li 3,12; bl _s80313A38_6; mr 30,3; mr 4,27; lis 3,-32693; stw 26,0x0(30); addi 3,3,31260; stw 28,0x4(30); stw 29,0x8(30); bl _s80313A38_7; mr 3,30; lwz 0,0x74(1); mtspr 8,0; lmw 25,0x54(1); addi 1,1,112"
extern "C" void _s80313A38_0();
extern "C" void _s80313A38_1();
extern "C" void _s80313A38_2();
extern "C" void _s80313A38_3();
extern "C" void _s80313A38_4();
extern "C" void _s80313A38_5();
extern "C" void _s80313A38_6();
extern "C" void _s80313A38_7();
extern "C" void f_80313A38() {}
