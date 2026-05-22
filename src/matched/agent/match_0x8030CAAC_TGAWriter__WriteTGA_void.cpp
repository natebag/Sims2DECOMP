// 0x8030CAAC TGAWriter::WriteTGA(void) (556 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-64(1); mfspr 0,8; stmw 22,0x18(1); stw 0,0x44(1); mr 31,3; li 28,0; lhz 9,0x14(31); addi 30,31,4; lhz 10,0x12(31); li 29,0; lbz 11,0x16(31); mullw 10,10,9; lbz 0,0xc(31); lhz 9,0xa(31); rlwinm 11,11,29,3,31; rlwinm 0,0,29,3,31; mullw 9,9,0; mullw 10,10,11; add 9,9,10; addi 23,9,44; bl _s8030CAAC_0; mr 4,23; li 5,0; bl _s8030CAAC_1; mr 24,3; li 4,0; mr 5,23; bl _s8030CAAC_2; lhz 0,0x14(31); mr 3,30; lhz 9,0x12(31); mr 4,24; stw 28,0x14(1); mullw 26,9,0; addi 28,24,18; bl _s8030CAAC_3; lwz 0,0x1c(31); cmpwi 0,0; beq 1f; cmplw 29,26; mr 22,30; addi 25,1,8; bge 3f; addi 30,1,16; 0:; lwz 11,0x18(31); mr 3,28; lwz 10,0x1c(31); addi 4,1,20; lbzx 9,11,29; li 5,4; addi 29,29,1; addi 28,28,4; rlwinm 9,9,2,0,29; lwzx 0,9,10; rlwinm 11,0,8,24,31; stw 0,0x14(1); stb 11,0x10(1); rlwinm 10,0,16,24,31; stb 10,0x1(30); rlwinm 8,10,16,0,15; lbz 9,0x16(1); stb 9,0x2(30); rlwinm 9,9,24,0,7; lbz 11,0x17(1); or 9,9,8; stb 11,0x3(30); lbz 0,0x10(1); rlwinm 0,0,8,0,23; or 9,9,0; or 9,9,11; stw 9,0x14(1); bl _s8030CAAC_4; cmplw 29,26; blt 0b; b 3f; 1:; cmplw 29,26; mr 22,30; li 27,0; addi 25,1,8; bge 3f; addi 30,1,16; li 29,0; 2:; lwz 9,0x18(31); mr 3,28; addi 4,1,20; li 5,4; lwzx 11,29,9; addi 27,27,1; addi 28,28,4; addi 29,29,4; rlwinm 0,11,8,24,31; stw 11,0x14(1); stb 0,0x10(1); rlwinm 10,11,16,24,31; rlwinm 0,11,24,24,31; stb 10,0x1(30); rlwinm 11,11,0,24,31; stb 0,0x2(30); stb 11,0x3(30); rlwinm 9,0,24,0,7; rlwinm 10,10,16,0,15; lbz 0,0x10(1); or 9,9,10; rlwinm 0,0,8,0,23; or 9,9,0; or 9,9,11; stw 9,0x14(1); bl _s8030CAAC_5; cmplw 27,26; blt 2b; 3:; mr 4,28; mr 3,22; bl _s8030CAAC_6; mr 3,25; bl _s8030CAAC_7; lwz 5,0x0(31); lis 4,-32702; addi 4,4,-728; mr 3,25; crxor 6,6,6; bl _s8030CAAC_8; lwz 4,0x8(1); mr 6,23; mr 5,24; mr 3,31; bl _s8030CAAC_9; mr 29,3; bl _s8030CAAC_10; mr 4,24; bl _s8030CAAC_11; lwz 4,0x8(1); mr 3,25; bl _s8030CAAC_12; mr 3,29; lwz 0,0x44(1); mtspr 8,0; lmw 22,0x18(1); addi 1,1,64"
extern "C" void _s8030CAAC_0();
extern "C" void _s8030CAAC_1();
extern "C" void _s8030CAAC_2();
extern "C" void _s8030CAAC_3();
extern "C" void _s8030CAAC_4();
extern "C" void _s8030CAAC_5();
extern "C" void _s8030CAAC_6();
extern "C" void _s8030CAAC_7();
extern "C" void _s8030CAAC_8();
extern "C" void _s8030CAAC_9();
extern "C" void _s8030CAAC_10();
extern "C" void _s8030CAAC_11();
extern "C" void _s8030CAAC_12();
extern "C" void f_8030CAAC() {}
