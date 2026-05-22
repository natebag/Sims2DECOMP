// 0x803363E4 THPGXYuv2RgbDraw(unsigned (476 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-152(1); mfspr 0,8; stmw 20,0x68(1); stw 0,0x9c(1); mr 21,4; mr 22,6; mr 23,7; mr 29,8; mr 28,9; mr 4,3; mr 20,5; mr 25,10; lha 24,0xa2(1); addi 3,1,8; li 9,0; li 10,0; rlwinm 5,29,0,16,31; rlwinm 6,28,0,16,31; li 7,1; li 8,0; bl _s803363E4_0; lis 26,-32702; lfs f1,0x1a94(26); addi 3,1,8; li 5,0; li 6,0; fmr f2,f1; li 7,0; fmr f3,f2; li 8,0; li 4,0; rlwinm 29,29,31,16,31; bl _s803363E4_1; rlwinm 28,28,31,16,31; addi 30,1,40; addi 3,1,8; li 4,0; bl _s803363E4_2; addi 27,1,72; li 9,0; li 10,0; mr 4,21; mr 3,30; mr 5,29; mr 6,28; li 7,1; li 8,0; bl _s803363E4_3; lfs f1,0x1a94(26); li 5,0; li 6,0; li 7,0; fmr f2,f1; li 8,0; fmr f3,f2; mr 3,30; li 4,0; bl _s803363E4_4; mr 3,30; li 4,1; bl _s803363E4_5; li 9,0; li 10,0; mr 4,20; mr 5,29; mr 6,28; mr 3,27; li 7,1; li 8,0; bl _s803363E4_6; lfs f1,0x1a94(26); li 5,0; li 6,0; li 7,0; fmr f2,f1; li 8,0; fmr f3,f2; mr 3,27; li 4,0; bl _s803363E4_7; mr 3,27; li 4,2; bl _s803363E4_8; li 3,128; li 4,0; li 5,4; bl _s803363E4_9; lis 9,-13311; li 0,1; sth 22,-32768(9); li 11,0; sth 23,-32768(9); add 25,22,25; sth 0,-32768(9); extsh 25,25; sth 11,-32768(9); add 24,23,24; sth 11,-32768(9); extsh 24,24; sth 25,-32768(9); sth 23,-32768(9); sth 11,-32768(9); sth 0,-32768(9); sth 11,-32768(9); sth 25,-32768(9); sth 24,-32768(9); sth 0,-32768(9); sth 0,-32768(9); sth 0,-32768(9); sth 22,-32768(9); sth 24,-32768(9); sth 0,-32768(9); sth 11,-32768(9); sth 0,-32768(9); lwz 0,0x9c(1); mtspr 8,0; lmw 20,0x68(1); addi 1,1,152"
extern "C" void _s803363E4_0();
extern "C" void _s803363E4_1();
extern "C" void _s803363E4_2();
extern "C" void _s803363E4_3();
extern "C" void _s803363E4_4();
extern "C" void _s803363E4_5();
extern "C" void _s803363E4_6();
extern "C" void _s803363E4_7();
extern "C" void _s803363E4_8();
extern "C" void _s803363E4_9();
extern "C" void f_803363E4() {}
