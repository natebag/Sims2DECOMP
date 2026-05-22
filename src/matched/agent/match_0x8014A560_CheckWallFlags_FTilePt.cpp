// 0x8014A560 CheckWallFlags(FTilePt, (924 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-200(1); mfspr 0,8; stmw 23,0xa4(1); stw 0,0xcc(1); lwz 9,0x0(3); lwz 10,0x4(3); mr 31,6; mr 6,4; mr 28,5; stw 9,0x98(1); stw 10,0x9c(1); addi 30,1,16; addi 3,1,8; mr 29,30; lwz 4,0x9c(1); lwz 5,0x98(1); srawi 4,4,4; srawi 5,5,4; bl _s8014A560_0; lwz 11,-21488(13); mr 3,30; addi 5,1,8; lwz 9,0x0(11); lwz 0,0xac(9); lha 4,0xa8(9); mtspr 8,0; add 4,11,4; blrl; mr 3,30; bl _s8014A560_1; andi. 0,31,64; beq 0f; cmpwi 3,0; bne 0f; li 0,23; mr 3,29; stw 0,-31888(13); b 22f; 0:; andi. 0,31,128; bne 1f; cmpwi 3,0; beq 1f; li 0,7; mr 3,29; stw 0,-31888(13); b 22f; 1:; cmpwi 31,0; beq 24f; subfic 0,28,8; rlwinm 4,0,31,30,31; cmpwi 4,0; beq 2f; mr 3,29; bl _s8014A560_2; 2:; mr 3,29; li 4,1; bl _s8014A560_3; li 30,0; cmpwi 3,0; beq 3f; mr 3,29; li 4,2; bl _s8014A560_4; cmpwi 3,0; bne 6f; 3:; mr 3,29; li 4,1; bl _s8014A560_5; cmpwi 3,0; beq 4f; mr 3,29; li 4,8; bl _s8014A560_6; cmpwi 3,0; bne 6f; 4:; mr 3,29; li 4,2; bl _s8014A560_7; cmpwi 3,0; beq 5f; mr 3,29; li 4,4; bl _s8014A560_8; cmpwi 3,0; bne 6f; 5:; mr 3,29; li 4,8; bl _s8014A560_9; cmpwi 3,0; beq 7f; mr 3,29; li 4,4; bl _s8014A560_10; cmpwi 3,0; beq 7f; 6:; li 30,1; 7:; andi. 0,31,32; beq 8f; cmpwi 30,0; bne 8f; li 0,4; mr 3,29; stw 0,-31888(13); b 22f; 8:; andi. 0,31,16; beq 10f; cmpwi 30,0; beq 10f; li 0,5; mr 3,29; stw 0,-31888(13); b 22f; 9:; li 0,7; mr 3,29; stw 0,-31888(13); b 22f; 10:; lis 9,-32706; addi 11,1,72; lwz 8,-9280(9); mr 25,11; addi 9,9,-9280; rlwinm 6,31,29,31,31; lwz 0,0x4(9); rlwinm 5,31,31,31,31; lwz 10,0x8(9); rlwinm 4,31,30,31,31; lwz 7,0xc(9); addi 27,1,136; stw 8,0x48(1); rlwinm 9,31,0,31,31; stw 0,0x4(11); rlwinm 8,31,22,31,31; stw 10,0x8(11); rlwinm 0,31,24,31,31; stw 7,0xc(11); rlwinm 10,31,23,31,31; rlwinm 11,31,21,31,31; stw 9,0x58(1); stw 6,0x5c(1); mr 26,27; stw 5,0x60(1); addi 28,1,120; stw 4,0x64(1); addi 24,1,104; stw 0,0x68(1); li 23,0; stw 11,0x6c(1); li 30,0; stw 10,0x70(1); li 31,4; stw 8,0x74(1); 11:; lwzx 4,30,25; mr 3,29; bl _s8014A560_11; stwx 3,30,26; stwx 23,30,28; lwzx 0,30,26; cmpwi 0,0; beq 17f; lwzx 4,30,25; mr 3,29; bl _s8014A560_12; li 9,0; cmpwi 3,1; beq 12f; cmpwi 3,7; beq 12f; cmpwi 3,8; beq 12f; cmpwi 3,9; bne 13f; 12:; li 0,1; b 14f; 13:; li 0,0; 14:; cmpwi 0,0; bne 15f; cmpwi 3,22; bne 16f; 15:; li 9,1; 16:; stwx 9,30,28; 17:; addi 30,30,4; addic. 31,31,-1; bne 11b; li 31,0; li 8,22; li 10,6; addi 11,1,88; li 9,0; 18:; lwzx 0,9,24; cmpwi 0,0; beq 19f; lwzx 0,9,27; cmpwi 0,0; bne 9b; 19:; lwz 0,0x0(11); cmpwi 0,0; beq 23f; lwzx 0,9,28; cmpwi 0,0; bne 23f; lwzx 0,9,27; cmpwi 0,0; beq 20f; stw 8,-31888(13); b 21f; 20:; stw 10,-31888(13); 21:; mr 3,29; 22:; li 4,2; bl _s8014A560_13; addi 3,1,8; li 4,2; bl _s8014A560_14; li 3,0; b 25f; 23:; addi 31,31,1; addi 11,11,4; addi 9,9,4; cmpwi 31,3; ble 18b; 24:; mr 3,29; li 4,2; bl _s8014A560_15; addi 3,1,8; li 4,2; bl _s8014A560_16; li 3,1; 25:; lwz 0,0xcc(1); mtspr 8,0; lmw 23,0xa4(1); addi 1,1,200"
extern "C" void _s8014A560_0();
extern "C" void _s8014A560_1();
extern "C" void _s8014A560_2();
extern "C" void _s8014A560_3();
extern "C" void _s8014A560_4();
extern "C" void _s8014A560_5();
extern "C" void _s8014A560_6();
extern "C" void _s8014A560_7();
extern "C" void _s8014A560_8();
extern "C" void _s8014A560_9();
extern "C" void _s8014A560_10();
extern "C" void _s8014A560_11();
extern "C" void _s8014A560_12();
extern "C" void _s8014A560_13();
extern "C" void _s8014A560_14();
extern "C" void _s8014A560_15();
extern "C" void _s8014A560_16();
extern "C" void f_8014A560() {}
