// 0x80221028 InteractorModule::WallManipulator::HandleFinalizeRequest(void) (692 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 26,0x10(1); stw 0,0x2c(1); mr 31,3; lwz 11,0x78(31); addi 10,31,120; lwz 0,0x4(10); mr 9,11; cmpw 11,0; beq 1f; 0:; addi 9,9,8; cmpw 9,0; bne 0b; 1:; stw 11,0x4(10); li 29,0; lwz 30,-21472(13); li 28,0; lwz 9,0x4(30); lwz 0,0x8(9); stw 0,0x8(1); mr 3,0; lwz 9,0x4(30); cmpw 3,9; stw 9,0x8(1); beq 4f; 2:; lwz 9,0x14(3); cmpwi 9,0; beq 3f; lwz 0,0x34(9); cmpwi 0,0; beq 3f; addi 28,28,1; 3:; bl _s80221028_0; lwz 0,0x4(30); cmpw 3,0; stw 0,0x8(1); bne 2b; 4:; lwz 0,0xc4(31); andi. 9,0,128; beq 8f; andi. 11,0,16; beq 5f; mr 3,31; bl _s80221028_1; b 7f; 5:; andi. 9,0,4; beq 6f; mr 3,31; bl _s80221028_2; b 7f; 6:; andi. 9,0,8; beq 8f; mr 3,31; bl _s80221028_3; mr 3,31; bl _s80221028_4; 7:; mr 29,3; 8:; lwz 0,0xc4(31); cmpwi 29,1; rlwinm 0,0,0,27,25; stw 0,0xc4(31); bne 18f; lwz 30,-21472(13); li 29,0; addi 26,31,96; addi 27,31,8; lwz 9,0x4(30); lwz 0,0x8(9); stw 0,0x8(1); mr 3,0; lwz 9,0x4(30); cmpw 3,9; stw 9,0x8(1); beq 11f; 9:; lwz 9,0x14(3); cmpwi 9,0; beq 10f; lwz 0,0x34(9); cmpwi 0,0; beq 10f; addi 29,29,1; 10:; bl _s80221028_5; lwz 0,0x4(30); cmpw 3,0; stw 0,0x8(1); bne 9b; 11:; cmpw 28,29; bge 12f; li 0,0; lhz 11,-21224(13); sth 0,0x8(1); addi 9,1,8; lhz 0,-21202(13); mr 4,9; sth 11,0x4(9); li 5,0; sth 11,0x2(9); sth 0,0x8(1); lwz 11,-21476(13); lwz 9,0x0(11); lha 3,0x1a0(9); lwz 0,0x1a4(9); add 3,11,3; mtspr 8,0; blrl; 12:; lwz 11,-21484(13); lwz 9,0x0(11); lwz 0,0x184(9); lha 3,0x180(9); mtspr 8,0; add 3,11,3; blrl; lwz 0,0xc4(31); andi. 9,0,4; beq 14f; lwz 0,-31536(13); cmpwi 0,0; bne 13f; li 3,120; bl _s80221028_6; bl _s80221028_7; stw 3,-31536(13); 13:; lis 4,-32543; lwz 3,-31536(13); ori 4,4,43469; bl _s80221028_8; b 16f; 14:; lwz 0,-31536(13); cmpwi 0,0; bne 15f; li 3,120; bl _s80221028_9; bl _s80221028_10; stw 3,-31536(13); 15:; lis 4,26334; lwz 3,-31536(13); ori 4,4,56946; bl _s80221028_11; 16:; lwz 11,0x8(31); li 10,-22; lwz 0,0x8(27); lwz 9,0x4(27); stw 11,0x60(31); stw 9,0x4(26); stw 0,0x8(26); lwz 0,0xc4(31); and 9,0,10; andi. 11,0,512; stw 9,0xc4(31); bne 17f; rlwinm 0,9,0,29,27; stw 0,0xc4(31); 17:; mr 3,31; li 4,0; bl _s80221028_12; b 20f; 18:; lwz 0,-31536(13); cmpwi 0,0; bne 19f; li 3,120; bl _s80221028_13; bl _s80221028_14; stw 3,-31536(13); 19:; lis 4,28199; lwz 3,-31536(13); ori 4,4,30903; bl _s80221028_15; 20:; lwz 0,0x2c(1); mtspr 8,0; lmw 26,0x10(1); addi 1,1,40"
extern "C" void _s80221028_0();
extern "C" void _s80221028_1();
extern "C" void _s80221028_2();
extern "C" void _s80221028_3();
extern "C" void _s80221028_4();
extern "C" void _s80221028_5();
extern "C" void _s80221028_6();
extern "C" void _s80221028_7();
extern "C" void _s80221028_8();
extern "C" void _s80221028_9();
extern "C" void _s80221028_10();
extern "C" void _s80221028_11();
extern "C" void _s80221028_12();
extern "C" void _s80221028_13();
extern "C" void _s80221028_14();
extern "C" void _s80221028_15();
extern "C" void f_80221028() {}
