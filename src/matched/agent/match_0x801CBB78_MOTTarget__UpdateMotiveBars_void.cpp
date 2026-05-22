// 0x801CBB78 MOTTarget::UpdateMotiveBars(void) (1096 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-296(1); mfspr 0,8; stmw 15,0xe4(1); stw 0,0x12c(1); mr 27,3; lwz 0,0x84(27); cmpwi 0,0; beq 23f; lwz 0,0x8c(27); lis 9,-32697; addi 9,9,24012; lwz 11,0x168(27); rlwinm 0,0,2,0,29; addi 9,9,188; lwzx 31,9,0; cmpwi 11,0; li 16,0; beq 3f; lwz 0,0x164(27); cmpw 31,0; beq 2f; stw 31,0x164(27); cmpwi 31,0; beq 1f; li 11,8; li 0,0; mtspr 9,11; addi 9,27,280; 0:; stw 0,0x0(9); addi 9,9,-4; bdnz 0b; mr 3,27; bl _s801CBB78_0; 1:; li 16,1; 2:; li 0,0; stw 0,0x168(27); 3:; cmpwi 31,0; beq 23f; lis 17,-32705; lis 18,-32705; addi 15,17,14100; addi 20,18,14112; li 21,0; addi 22,27,252; addi 19,1,136; li 26,0; 4:; lwzx 9,26,22; cmpwi 9,0; beq 5f; addi 0,9,-1; stwx 0,26,22; b 16f; 5:; li 0,4; mr 3,27; stwx 0,26,22; mr 4,21; bl _s801CBB78_1; addi 9,27,156; addi 11,27,188; stwx 3,9,26; mr 8,9; li 5,0; mr 25,11; lwzx 0,11,26; cmpw 3,0; bne 7f; addi 9,27,316; mr 10,5; lwzx 0,9,26; li 5,22; cmpwi 0,0; bne 6f; stwx 10,26,22; b 9f; 6:; cmpwi 0,2; beq 8f; cmpwi 0,1; bne 9f; li 5,0; b 9f; 7:; li 10,1; bgt 9f; li 10,-1; 8:; li 5,11; 9:; cmpwi 16,0; bne 11f; lwzx 9,8,26; cmpwi 9,0; beq 11f; lwzx 0,25,26; subf. 11,0,9; blt 10f; cmpwi 11,3; bgt 11f; b 12f; 10:; subf 0,9,0; cmpwi 0,3; ble 12f; 11:; li 9,0; li 5,22; stwx 9,26,22; lwzx 0,8,26; b 13f; 12:; lwzx 0,25,26; add 0,0,10; 13:; stwx 0,25,26; lwzx 0,25,26; lwz 9,0x88(27); add 28,5,0; cmpwi 9,0; beq 16f; addi 9,27,220; lwzx 0,9,26; cmpw 28,0; beq 16f; stwx 28,9,26; addi 29,1,72; addi 31,1,8; lis 24,-32705; lwz 0,0x3714(17); addi 30,1,200; lwz 9,0x4(15); mr 5,21; stw 0,0x8(1); addi 4,24,7944; stw 9,0x4(31); mr 3,29; crxor 6,6,6; bl _s801CBB78_2; mr 23,30; mr 4,29; mr 3,31; bl _s801CBB78_3; lis 9,-32705; lis 4,-32705; lhz 0,0x371c(9); mr 5,28; addi 4,4,-8800; mr 3,29; sth 0,0x88(1); crxor 6,6,6; bl _s801CBB78_4; mr 4,29; mr 3,19; bl _s801CBB78_5; mr 3,30; bl _s801CBB78_6; mr 3,30; bl _s801CBB78_7; lwz 5,0x8c(27); mr 3,30; mr 4,31; bl _s801CBB78_8; mr 3,30; mr 4,19; bl _s801CBB78_9; lwzx 0,25,26; cmpwi 0,1; bgt 14f; lwz 11,0x3720(18); mr 5,21; lwz 9,0x4(20); addi 4,24,7944; lbz 0,0x8(20); mr 3,29; stw 11,0x8(1); stw 9,0x4(31); stb 0,0x8(31); crxor 6,6,6; bl _s801CBB78_10; mr 4,29; mr 3,31; bl _s801CBB78_11; lwz 5,0x8c(27); mr 4,31; mr 3,23; bl _s801CBB78_12; lis 4,-32705; mr 3,23; addi 4,4,12800; bl _s801CBB78_13; b 15f; 14:; lwz 11,0x3720(18); mr 5,21; lwz 9,0x4(20); addi 4,24,7944; lbz 0,0x8(20); mr 3,29; stw 11,0x8(1); stw 9,0x4(31); stb 0,0x8(31); crxor 6,6,6; bl _s801CBB78_14; mr 4,29; mr 3,31; bl _s801CBB78_15; lwz 5,0x8c(27); mr 4,31; mr 3,23; bl _s801CBB78_16; lis 4,-32705; mr 3,23; addi 4,4,3316; bl _s801CBB78_17; 15:; mr 3,23; bl _s801CBB78_18; mr 3,23; li 4,2; bl _s801CBB78_19; 16:; addi 21,21,1; addi 26,26,4; cmpwi 21,7; ble 4b; lis 9,-32697; lwz 0,0x5bcc(9); cmpwi 0,0; beq 23f; li 0,7; lwz 11,0x9c(27); mtspr 9,0; lwz 4,0x8c(27); addi 9,27,160; 17:; lwz 0,0x0(9); addi 9,9,4; cmpw 0,11; bge 18f; mr 11,0; 18:; bdnz 17b; cmpwi 11,1; bgt 19f; lis 9,-32697; li 5,1; lwz 3,0x5bcc(9); bl _s801CBB78_20; b 20f; 19:; lis 9,-32697; li 5,0; lwz 3,0x5bcc(9); bl _s801CBB78_21; 20:; lwz 11,0x164(27); cmpwi 11,0; beq 23f; lwz 9,0x4(11); li 4,3; lha 3,0x58(9); lwz 0,0x5c(9); add 3,11,3; mtspr 8,0; blrl; lis 9,-32705; lis 11,-32705; lfs f0,0x372c(9); lis 10,-32705; lfs f13,0x3730(11); fadds f1,f1,f0; fdivs f1,f1,f13; lfs f0,0x3734(10); fcmpu 0,f1,f0; bgt 21f; lis 9,-32705; lfs f0,0x3738(9); fcmpu 0,f1,f0; bge 22f; 21:; fmr f1,f0; 22:; lis 9,-32697; lwz 4,0x8c(27); lwz 3,0x5bcc(9); xori 5,16,1; bl _s801CBB78_22; 23:; lwz 0,0x12c(1); mtspr 8,0; lmw 15,0xe4(1); addi 1,1,296"
extern "C" void _s801CBB78_0();
extern "C" void _s801CBB78_1();
extern "C" void _s801CBB78_2();
extern "C" void _s801CBB78_3();
extern "C" void _s801CBB78_4();
extern "C" void _s801CBB78_5();
extern "C" void _s801CBB78_6();
extern "C" void _s801CBB78_7();
extern "C" void _s801CBB78_8();
extern "C" void _s801CBB78_9();
extern "C" void _s801CBB78_10();
extern "C" void _s801CBB78_11();
extern "C" void _s801CBB78_12();
extern "C" void _s801CBB78_13();
extern "C" void _s801CBB78_14();
extern "C" void _s801CBB78_15();
extern "C" void _s801CBB78_16();
extern "C" void _s801CBB78_17();
extern "C" void _s801CBB78_18();
extern "C" void _s801CBB78_19();
extern "C" void _s801CBB78_20();
extern "C" void _s801CBB78_21();
extern "C" void _s801CBB78_22();
extern "C" void f_801CBB78() {}
