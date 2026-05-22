// 0x801BE81C K2YTarget::GetVariable(char (740 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-64(1); mfspr 0,8; stmw 25,0x24(1); stw 0,0x44(1); mr 27,3; mr 29,4; li 3,32; bl _s801BE81C_0; mr 31,3; li 0,0; lis 3,-32705; stb 0,0x0(31); addi 3,3,7212; mr 4,29; bl _s801BE81C_1; cmpwi 3,0; bne 0f; lis 9,-32705; addi 11,9,-8792; lwz 10,-8792(9); lbz 8,0x6(11); lhz 0,0x4(11); stw 10,0x0(31); sth 0,0x4(31); stb 8,0x6(31); b 16f; 0:; lis 3,-32705; mr 4,29; addi 3,3,7240; bl _s801BE81C_2; cmpwi 3,0; bne 1f; lis 5,-32705; mr 3,31; addi 5,5,-8800; li 4,32; li 6,0; crxor 6,6,6; bl _s801BE81C_3; b 16f; 1:; lis 3,-32705; mr 4,29; addi 3,3,7224; bl _s801BE81C_4; cmpwi 3,0; bne 3f; mr 3,27; bl _s801BE81C_5; cmpwi 3,0; beq 16f; mr 3,27; bl _s801BE81C_6; mr 29,3; bl _s801BE81C_7; lis 30,-32697; lis 9,-32705; lis 11,-32705; addi 30,30,24012; mr 28,3; lfs f1,0x1e70(9); lfs f2,0x1e74(11); li 4,1; lwz 3,0x104(30); bl _s801BE81C_8; lwz 4,0x104(30); mr 5,29; addi 3,1,16; li 6,1; li 7,0; li 8,0; bl _s801BE81C_9; lwz 11,0x10(1); lis 9,-32705; lfs f13,0x1e78(9); stw 11,0x8(1); lwz 0,0x14(1); lfs f0,0x8(1); stw 0,0xc(1); fcmpu 0,f0,f13; ble 2f; li 28,15; 2:; lis 5,-32705; mr 6,28; addi 5,5,-8800; mr 3,31; li 4,32; crxor 6,6,6; bl _s801BE81C_10; b 16f; 3:; lis 3,-32705; mr 4,29; addi 3,3,7772; li 5,6; bl _s801BE81C_11; mr. 0,3; bne 6f; addi 3,29,6; lis 30,-32705; stb 0,0x1(3); addi 5,1,24; addi 4,30,-8800; stw 0,0x18(1); stw 0,0x1c(1); lis 25,-32705; crxor 6,6,6; bl _s801BE81C_12; lis 26,-32705; addi 4,30,-8800; addi 5,1,28; addi 3,29,11; li 28,12; crxor 6,6,6; bl _s801BE81C_13; lwz 4,0x18(1); mr 3,27; lwz 5,0x1c(1); bl _s801BE81C_14; mr 30,3; 4:; rlwinm 0,30,0,31,31; cmpwi 0,0; srawi 30,30,1; addi 4,25,-5284; beq 5f; addi 4,26,-5288; 5:; mr 3,31; bl _s801BE81C_15; addic. 28,28,-1; bne 4b; li 0,0; stb 0,0xc(31); b 16f; 6:; lis 3,-32705; mr 4,29; addi 3,3,7256; bl _s801BE81C_16; cmpwi 3,0; bne 16f; lwz 0,-30256(13); cmpwi 0,4; beq 10f; bgt 8f; cmpwi 0,1; beq 13f; bgt 7f; cmpwi 0,0; b 14f; 7:; cmpwi 0,2; beq 10f; cmpwi 0,3; beq 11f; b 14f; 8:; cmpwi 0,7; beq 10f; bgt 9f; cmpwi 0,5; beq 11f; cmpwi 0,6; beq 12f; b 14f; 9:; cmpwi 0,8; beq 11f; b 14f; 10:; lis 9,-32705; lhz 0,-5284(9); b 15f; 11:; lis 9,-32705; lhz 0,-5288(9); b 15f; 12:; lis 9,-32705; lhz 0,0x1e64(9); b 15f; 13:; lis 9,-32705; lhz 0,0x1e6c(9); b 15f; 14:; lis 9,-32705; lhz 0,0x1e68(9); 15:; sth 0,0x0(31); 16:; li 0,0; mr 3,31; stb 0,0x1f(31); lwz 0,0x44(1); mtspr 8,0; lmw 25,0x24(1); addi 1,1,64"
extern "C" void _s801BE81C_0();
extern "C" void _s801BE81C_1();
extern "C" void _s801BE81C_2();
extern "C" void _s801BE81C_3();
extern "C" void _s801BE81C_4();
extern "C" void _s801BE81C_5();
extern "C" void _s801BE81C_6();
extern "C" void _s801BE81C_7();
extern "C" void _s801BE81C_8();
extern "C" void _s801BE81C_9();
extern "C" void _s801BE81C_10();
extern "C" void _s801BE81C_11();
extern "C" void _s801BE81C_12();
extern "C" void _s801BE81C_13();
extern "C" void _s801BE81C_14();
extern "C" void _s801BE81C_15();
extern "C" void _s801BE81C_16();
extern "C" void f_801BE81C() {}
