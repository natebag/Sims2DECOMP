// 0x801BE56C K2YTarget::SetVariable(char (688 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 28,0x10(1); stw 0,0x24(1); mr 30,3; mr 31,4; lis 3,-32705; mr 28,5; addi 3,3,7504; bl _s801BE56C_0; mr. 29,3; bne 3f; mr 3,30; bl _s801BE56C_1; cmpwi 3,0; beq 23f; mr 3,30; bl _s801BE56C_2; mr 31,3; bl _s801BE56C_3; mr. 3,3; beq 1f; lwz 0,-31536(13); add 9,3,3; add 9,9,31; sth 29,-2(9); cmpwi 0,0; bne 0f; li 3,120; bl _s801BE56C_4; bl _s801BE56C_5; stw 3,-31536(13); 0:; lis 4,1162; lwz 3,-31536(13); ori 4,4,59727; bl _s801BE56C_6; b 23f; 1:; lwz 0,-31536(13); cmpwi 0,0; bne 2f; li 3,120; bl _s801BE56C_7; bl _s801BE56C_8; stw 3,-31536(13); 2:; lis 4,14340; lwz 3,-31536(13); ori 4,4,8607; bl _s801BE56C_9; b 23f; 3:; lis 3,-32705; mr 4,31; addi 3,3,7516; bl _s801BE56C_10; cmpwi 3,0; bne 5f; mr 3,30; bl _s801BE56C_11; cmpwi 3,0; beq 23f; mr 3,30; bl _s801BE56C_12; mr 31,3; lis 4,-32697; addi 4,4,24012; mr 5,28; addi 3,1,8; crxor 6,6,6; bl _s801BE56C_13; lwz 9,0x8(1); li 4,0; cmpwi 9,0; beq 4f; lwz 4,0x0(9); 4:; cmpwi 4,0; beq 23f; mr 3,31; bl _s801BE56C_14; b 13f; 5:; lis 3,-32705; mr 4,31; addi 3,3,7524; bl _s801BE56C_15; cmpwi 3,0; bne 6f; mr 3,30; bl _s801BE56C_16; cmpwi 3,0; beq 23f; mr 3,30; bl _s801BE56C_17; mr. 3,3; beq 23f; lis 4,-32705; addi 4,4,7140; bl _s801BE56C_18; b 13f; 6:; lis 3,-32705; mr 4,31; addi 3,3,7536; bl _s801BE56C_19; cmpwi 3,0; bne 15f; lwz 0,-30256(13); cmpwi 0,4; beq 9f; bgt 7f; cmpwi 0,2; beq 8f; b 11f; 7:; cmpwi 0,7; beq 10f; b 11f; 8:; li 0,3; b 12f; 9:; li 0,5; b 12f; 10:; li 0,8; b 12f; 11:; li 0,0; 12:; stw 0,-30256(13); 13:; lwz 0,-31536(13); cmpwi 0,0; bne 14f; li 3,120; bl _s801BE56C_20; bl _s801BE56C_21; stw 3,-31536(13); 14:; lis 4,14155; lwz 3,-31536(13); ori 4,4,56554; bl _s801BE56C_22; b 23f; 15:; lis 3,-32705; mr 4,31; addi 3,3,7548; bl _s801BE56C_23; cmpwi 3,0; bne 23f; lwz 0,-30256(13); cmpwi 0,5; beq 18f; bgt 16f; cmpwi 0,3; beq 17f; b 20f; 16:; cmpwi 0,8; beq 19f; b 20f; 17:; li 0,2; b 21f; 18:; li 0,4; b 21f; 19:; li 0,7; b 21f; 20:; li 0,1; 21:; stw 0,-30256(13); lwz 0,-31536(13); cmpwi 0,0; bne 22f; li 3,120; bl _s801BE56C_24; bl _s801BE56C_25; stw 3,-31536(13); 22:; lis 4,14155; lwz 3,-31536(13); ori 4,4,56554; bl _s801BE56C_26; 23:; lwz 0,0x24(1); mtspr 8,0; lmw 28,0x10(1); addi 1,1,32"
extern "C" void _s801BE56C_0();
extern "C" void _s801BE56C_1();
extern "C" void _s801BE56C_2();
extern "C" void _s801BE56C_3();
extern "C" void _s801BE56C_4();
extern "C" void _s801BE56C_5();
extern "C" void _s801BE56C_6();
extern "C" void _s801BE56C_7();
extern "C" void _s801BE56C_8();
extern "C" void _s801BE56C_9();
extern "C" void _s801BE56C_10();
extern "C" void _s801BE56C_11();
extern "C" void _s801BE56C_12();
extern "C" void _s801BE56C_13();
extern "C" void _s801BE56C_14();
extern "C" void _s801BE56C_15();
extern "C" void _s801BE56C_16();
extern "C" void _s801BE56C_17();
extern "C" void _s801BE56C_18();
extern "C" void _s801BE56C_19();
extern "C" void _s801BE56C_20();
extern "C" void _s801BE56C_21();
extern "C" void _s801BE56C_22();
extern "C" void _s801BE56C_23();
extern "C" void _s801BE56C_24();
extern "C" void _s801BE56C_25();
extern "C" void _s801BE56C_26();
extern "C" void f_801BE56C() {}
