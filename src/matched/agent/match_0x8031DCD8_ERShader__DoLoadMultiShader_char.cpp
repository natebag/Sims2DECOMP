// 0x8031DCD8 ERShader::DoLoadMultiShader(char (776 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 27,0x14(1); stw 0,0x2c(1); mr 31,3; mr 29,4; lwz 0,0x58(31); mr 27,5; addi 3,1,8; ori 0,0,2; li 5,1; stw 0,0x58(31); addi 29,29,1; bl _s8031DCD8_0; lbz 0,0x8(1); cmpwi 0,1; stw 0,0x3c(31); beq 2f; bgt 0f; cmpwi 0,0; beq 1f; b 5f; 0:; cmpwi 0,2; beq 3f; b 5f; 1:; lwz 0,0x58(31); ori 0,0,16; b 4f; 2:; lwz 0,0x58(31); ori 0,0,32; b 4f; 3:; lwz 0,0x58(31); ori 0,0,64; 4:; stw 0,0x58(31); 5:; mr 4,29; li 5,4; addi 3,31,64; addi 29,29,4; bl _s8031DCD8_1; addi 28,31,60; mr 4,29; li 5,1; addi 3,31,68; addi 29,29,1; bl _s8031DCD8_2; mr 3,28; bl _s8031DCD8_3; lbz 4,0x8(28); cmpwi 4,0; beq 6f; lis 30,-32692; li 5,8; addi 3,30,-17444; bl _s8031DCD8_4; lbz 4,0x8(28); li 5,8; stw 3,0xc(28); addi 3,30,-17444; rlwinm 4,4,2,0,29; bl _s8031DCD8_5; stw 3,0x10(28); 6:; lbz 0,0x44(31); li 30,0; cmpw 30,0; bge 8f; 7:; lwz 3,0x48(31); mr 4,29; li 5,1; addi 29,29,1; add 3,3,30; bl _s8031DCD8_6; addi 30,30,1; lbz 0,0x44(31); cmpw 30,0; blt 7b; 8:; lbz 0,0x44(31); li 30,0; cmpw 30,0; bge 10f; li 28,0; 9:; lwz 3,0x4c(31); mr 4,29; li 5,4; addi 30,30,1; add 3,28,3; addi 29,29,4; bl _s8031DCD8_7; addi 28,28,4; lbz 0,0x44(31); cmpw 30,0; blt 9b; 10:; lbz 0,0x44(31); rlwinm 11,0,0,24,31; mr 9,0; cmpwi 11,0; beq 24f; li 5,0; addic. 10,11,-1; ble 15f; 11:; addi 8,5,1; rlwinm 0,0,0,24,31; mr 3,8; cmpw 8,0; bge 14f; rlwinm 4,5,2,0,29; rlwinm 6,3,2,0,29; 12:; lwz 9,0x48(31); lbzx 0,9,8; mr 11,9; lbzx 7,9,5; cmplw 7,0; ble 13f; lwz 9,0x4c(31); lwzx 10,4,9; stbx 0,11,5; lwz 9,0x4c(31); lwzx 0,6,9; stwx 0,4,9; lwz 11,0x48(31); stbx 7,11,8; lwz 9,0x4c(31); stwx 10,6,9; 13:; lbz 0,0x44(31); addi 8,8,1; addi 6,6,4; mr 9,0; cmpw 8,0; blt 12b; 14:; addi 0,9,-1; mr 5,3; cmpw 5,0; mr 0,9; blt 11b; 15:; rlwinm 0,9,0,24,31; cmpwi 0,0; beq 24f; lwz 8,-26656(13); cmpwi 8,0; beq 20f; lwz 0,-26652(13); li 9,0; lwz 11,0x48(31); mr 6,0; cmplw 9,0; bge 17f; lwz 10,0x8(31); lwz 0,0x0(8); cmpw 10,0; beq 17f; mr 7,10; mr 10,6; 16:; addi 9,9,1; cmplw 9,10; bge 17f; lwzu 0,0x4(8); cmpw 7,0; bne 16b; 17:; cmpw 9,6; bne 18f; lbz 4,0x0(11); b 19f; 18:; lbz 4,0x1(11); 19:; mr 3,31; bl _s8031DCD8_8; b 22f; 20:; lbz 11,-26648(13); cmplw 11,0; bge 21f; lwz 9,0x48(31); mr 3,31; lbzx 4,9,11; bl _s8031DCD8_9; b 22f; 21:; lwz 9,0x48(31); mr 3,31; lbz 4,0x0(9); bl _s8031DCD8_10; 22:; lwz 4,0x14(31); cmpwi 4,0; bne 23f; lwz 9,0x18(31); li 4,0; cmpwi 9,0; beq 23f; lwz 4,0x14(9); 23:; mr 3,27; bl _s8031DCD8_11; 24:; mr 3,31; bl _s8031DCD8_12; lwz 0,0x2c(1); mtspr 8,0; lmw 27,0x14(1); addi 1,1,40"
extern "C" void _s8031DCD8_0();
extern "C" void _s8031DCD8_1();
extern "C" void _s8031DCD8_2();
extern "C" void _s8031DCD8_3();
extern "C" void _s8031DCD8_4();
extern "C" void _s8031DCD8_5();
extern "C" void _s8031DCD8_6();
extern "C" void _s8031DCD8_7();
extern "C" void _s8031DCD8_8();
extern "C" void _s8031DCD8_9();
extern "C" void _s8031DCD8_10();
extern "C" void _s8031DCD8_11();
extern "C" void _s8031DCD8_12();
extern "C" void f_8031DCD8() {}
