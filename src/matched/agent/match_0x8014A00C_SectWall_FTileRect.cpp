// 0x8014A00C SectWall(FTileRect (588 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-112(1); mfspr 0,8; stmw 22,0x48(1); stw 0,0x74(1); mr 31,3; mr 23,4; lwz 9,0x0(31); lwz 10,0x8(31); lwz 11,0x4(31); addi 9,9,-1; lwz 0,0xc(31); srawi 24,9,4; addi 11,11,-1; srawi 26,10,4; srawi 22,0,4; srawi 25,11,4; cmpw 26,24; bgt 17f; 0:; mr 27,22; cmpw 27,25; bgt 16f; addi 28,1,16; 1:; mr 6,23; mr 4,27; addi 3,1,8; mr 5,26; bl _s8014A00C_0; lwz 4,-21488(13); mr 3,28; addi 5,1,8; lwz 9,0x0(4); lha 0,0xa8(9); lwz 9,0xac(9); add 4,4,0; mtspr 8,9; blrl; mr 3,28; bl _s8014A00C_1; mr. 29,3; beq 15f; 2:; mr 3,28; mr 4,29; bl _s8014A00C_2; cmpwi 3,3; beq 3f; cmpwi 3,5; beq 3f; cmpwi 3,6; beq 3f; cmpwi 3,15; beq 3f; cmpwi 3,23; bne 4f; 3:; li 0,1; b 5f; 4:; li 0,0; 5:; cmpwi 0,0; bne 14f; cmpwi 29,2; beq 8f; bgt 6f; cmpwi 29,1; beq 7f; b 14f; 6:; cmpwi 29,16; beq 9f; cmpwi 29,32; beq 10f; b 14f; 7:; addi 3,1,8; bl _s8014A00C_3; rlwinm 3,3,4,0,27; lwz 10,0xc(31); lwz 9,0x4(31); b 11f; 8:; addi 3,1,8; bl _s8014A00C_4; rlwinm 3,3,4,0,27; lwz 10,0x8(31); lwz 9,0x0(31); b 11f; 9:; addi 3,1,8; bl _s8014A00C_5; mr 30,3; addi 3,1,8; bl _s8014A00C_6; add 30,30,3; lwz 10,0x0(31); lwz 11,0x4(31); addi 30,30,1; lwz 9,0x8(31); rlwinm 3,30,4,0,27; lwz 0,0xc(31); add 10,10,11; add 9,9,0; b 11f; 10:; addi 3,1,8; bl _s8014A00C_7; mr 30,3; addi 3,1,8; bl _s8014A00C_8; lwz 10,0x8(31); subf 30,3,30; lwz 11,0x4(31); rlwinm 3,30,4,0,27; lwz 9,0x0(31); lwz 0,0xc(31); subf 10,11,10; subf 9,0,9; 11:; cmpw cr7,10,3; bge cr7,12f; cmpw 9,3; bgt 13f; 12:; ble cr7,14f; cmpw 9,3; bge 14f; 13:; mr 3,28; li 4,2; bl _s8014A00C_9; addi 3,1,8; li 4,2; bl _s8014A00C_10; li 3,1; b 18f; 14:; mr 4,29; mr 3,28; bl _s8014A00C_11; mr. 29,3; bne 2b; 15:; mr 3,28; li 4,2; bl _s8014A00C_12; addi 27,27,1; addi 3,1,8; li 4,2; bl _s8014A00C_13; cmpw 27,25; ble 1b; 16:; addi 26,26,1; cmpw 26,24; ble 0b; 17:; li 3,0; 18:; lwz 0,0x74(1); mtspr 8,0; lmw 22,0x48(1); addi 1,1,112"
extern "C" void _s8014A00C_0();
extern "C" void _s8014A00C_1();
extern "C" void _s8014A00C_2();
extern "C" void _s8014A00C_3();
extern "C" void _s8014A00C_4();
extern "C" void _s8014A00C_5();
extern "C" void _s8014A00C_6();
extern "C" void _s8014A00C_7();
extern "C" void _s8014A00C_8();
extern "C" void _s8014A00C_9();
extern "C" void _s8014A00C_10();
extern "C" void _s8014A00C_11();
extern "C" void _s8014A00C_12();
extern "C" void _s8014A00C_13();
extern "C" void f_8014A00C() {}
