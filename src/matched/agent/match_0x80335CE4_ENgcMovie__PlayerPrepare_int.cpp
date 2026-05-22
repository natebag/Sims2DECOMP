// 0x80335CE4 ENgcMovie::PlayerPrepare(int, (556 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 27,0xc(1); stw 0,0x24(1); lis 9,-32691; mr 29,4; addi 31,9,14656; mr 27,5; lwz 0,0xa0(31); mr 28,6; cmpwi 0,0; beq 8f; lbz 0,0xa4(31); cmpwi 0,0; bne 8f; cmpwi 29,0; ble 0f; lwz 9,0x60(31); cmpwi 9,0; beq 8f; lwz 0,0x50(31); cmpw 0,29; ble 8f; addi 6,29,-1; lis 30,-32691; rlwinm 6,6,2,0,29; mr 3,31; add 6,9,6; addi 4,30,20224; li 5,32; li 7,2; bl _s80335CE4_0; cmpwi 3,0; blt 8f; addi 11,30,20224; lwz 10,0x4f00(30); lwz 0,0x4(11); lwz 9,0x64(31); subf 0,10,0; stw 29,0xc0(31); add 9,9,10; stw 0,0xbc(31); stw 9,0xb8(31); b 1f; 0:; lwz 0,0x64(31); lwz 9,0x54(31); stw 29,0xc0(31); stw 0,0xb8(31); stw 9,0xbc(31); 1:; lis 9,-32691; addi 9,9,14656; lbz 0,0xa7(9); cmpwi 0,0; beq 2f; cmpwi 28,0; blt 8f; lwz 0,0x98(9); cmpw 28,0; bge 8f; stw 28,0xec(9); 2:; lis 9,-32691; li 11,0; addi 31,9,14656; rlwinm 27,27,0,31,31; lwz 0,0xb0(31); stb 27,0xa6(31); stw 11,0xd8(31); cmpwi 0,0; beq 3f; lwz 4,0xb4(31); mr 3,31; lwz 5,0x58(31); li 7,2; lwz 6,0x64(31); bl _s80335CE4_1; cmpwi 3,0; blt 8f; lwz 0,0xb4(31); li 3,11; lwz 9,0xb8(31); lwz 11,0x64(31); add 0,0,9; subf 30,11,0; mr 4,30; bl _s80335CE4_2; lbz 0,0xa7(31); cmpwi 0,0; beq 5f; mr 4,30; li 3,12; bl _s80335CE4_3; b 5f; 3:; li 3,11; li 4,0; bl _s80335CE4_4; lbz 0,0xa7(31); cmpwi 0,0; beq 4f; li 3,12; li 4,0; bl _s80335CE4_5; 4:; li 3,13; bl _s80335CE4_6; 5:; bl _s80335CE4_7; bl _s80335CE4_8; lis 9,-32691; addi 31,9,14656; lbz 0,0xa7(31); cmpwi 0,0; beq 6f; bl _s80335CE4_9; 6:; lwz 0,0xb0(31); cmpwi 0,0; bne 7f; bl _s80335CE4_10; 7:; bl _s80335CE4_11; cmpwi 3,0; beq 8f; li 0,0; li 9,1; li 11,0; lis 3,-32717; stw 0,0xf4(31); addi 3,3,26348; stb 9,0xa4(31); stb 11,0xa5(31); stw 0,0xf8(31); stw 0,0xfc(31); stw 0,0xf0(31); bl _s80335CE4_12; stw 3,-26364(13); li 3,1; b 9f; 8:; li 3,0; 9:; lwz 0,0x24(1); mtspr 8,0; lmw 27,0xc(1); addi 1,1,32"
extern "C" void _s80335CE4_0();
extern "C" void _s80335CE4_1();
extern "C" void _s80335CE4_2();
extern "C" void _s80335CE4_3();
extern "C" void _s80335CE4_4();
extern "C" void _s80335CE4_5();
extern "C" void _s80335CE4_6();
extern "C" void _s80335CE4_7();
extern "C" void _s80335CE4_8();
extern "C" void _s80335CE4_9();
extern "C" void _s80335CE4_10();
extern "C" void _s80335CE4_11();
extern "C" void _s80335CE4_12();
extern "C" void f_80335CE4() {}
