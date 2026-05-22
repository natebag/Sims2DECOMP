// 0x80182990 WidgetScreenFormat::IsDataValid(char (1196 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-48(1); mfspr 0,8; stmw 24,0x10(1); stw 0,0x34(1); lis 9,-32706; mr 30,3; addi 9,9,16216; mr 26,4; addi 29,9,-8; li 25,0; li 27,0; li 28,-1; lis 24,-32705; 0:; lwzu 31,0x8(29); addi 4,24,-23988; addi 28,28,1; mr 3,31; bl _s80182990_0; cmpwi 3,0; bne 1f; li 27,1; b 2f; 1:; mr 3,31; mr 4,26; bl _s80182990_1; cmpwi 3,0; bne 2f; li 25,1; 2:; cmpwi 25,0; bne 3f; cmpwi 27,0; beq 0b; 3:; lis 9,-32706; rlwinm 0,28,3,0,28; addi 9,9,16216; li 25,1; addi 9,9,4; lwzx 0,9,0; cmpwi 0,10; beq 11f; bgt 5f; cmpwi 0,4; beq 14f; bgt 4f; cmpwi 0,2; bgt 7f; cmpwi 0,1; bge 14f; cmpwi 0,0; beq 19f; b 18f; 4:; cmpwi 0,6; beq 17f; blt 14f; cmpwi 0,8; beq 8f; cmpwi 0,9; beq 10f; b 18f; 5:; cmpwi 0,17; beq 15f; bgt 6f; cmpwi 0,12; beq 13f; blt 12f; cmpwi 0,13; beq 14f; cmpwi 0,16; beq 14f; b 18f; 6:; cmpwi 0,19; beq 17f; blt 16f; cmpwi 0,24; bgt 18f; b 19f; 7:; lwz 3,0x8(30); bl _s80182990_2; xoris 3,3,32768; stw 3,0xc(1); lis 0,17200; lis 11,-32705; lis 10,-32705; stw 0,0x8(1); lfd f13,-23720(11); lfd f0,0x8(1); lfs f12,-23712(10); fsub f0,f0,f13; frsp f13,f0; fcmpu 0,f13,f12; bge 19f; lis 9,-32705; lfs f0,-23708(9); fcmpu 0,f13,f0; ble 19f; b 18f; 8:; lwz 3,0x8(30); lis 4,-32705; addi 4,4,-23976; li 5,5; bl _s80182990_3; cmpwi 3,0; beq 19f; lwz 3,0x8(30); lis 4,-32705; addi 4,4,-23968; li 5,3; bl _s80182990_4; cmpwi 3,0; beq 19f; lwz 3,0x8(30); lis 4,-32705; addi 4,4,-24012; li 5,7; bl _s80182990_5; 9:; cmpwi 3,0; beq 19f; b 18f; 10:; lwz 3,0x8(30); lis 4,-32705; addi 4,4,-23964; bl _s80182990_6; cmpwi 3,0; beq 19f; lwz 3,0x8(30); lis 4,-32705; addi 4,4,-23956; bl _s80182990_7; cmpwi 3,0; beq 19f; lwz 3,0x8(30); lis 4,-32705; addi 4,4,-23948; bl _s80182990_8; cmpwi 3,0; beq 19f; lwz 3,0x8(30); lis 4,-32705; addi 4,4,-23940; bl _s80182990_9; cmpwi 3,0; beq 19f; lwz 3,0x8(30); lis 4,-32705; addi 4,4,-23924; bl _s80182990_10; cmpwi 3,0; beq 19f; lwz 3,0x8(30); lis 4,-32705; addi 4,4,-23908; bl _s80182990_11; cmpwi 3,0; beq 19f; lwz 3,0x8(30); lis 4,-32705; addi 4,4,-23900; bl _s80182990_12; cmpwi 3,0; beq 19f; lwz 3,0x8(30); lis 4,-32705; addi 4,4,-23884; bl _s80182990_13; cmpwi 3,0; beq 19f; lwz 3,0x8(30); lis 4,-32705; addi 4,4,-23864; bl _s80182990_14; cmpwi 3,0; beq 19f; lwz 3,0x8(30); lis 4,-32705; addi 4,4,-23852; bl _s80182990_15; cmpwi 3,0; beq 19f; lwz 3,0x8(30); lis 4,-32705; addi 4,4,-23840; bl _s80182990_16; cmpwi 3,0; beq 19f; lwz 3,0x8(30); lis 4,-32705; addi 4,4,-23832; bl _s80182990_17; cmpwi 3,0; beq 19f; lwz 3,0x8(30); lis 4,-32705; addi 4,4,-23820; bl _s80182990_18; cmpwi 3,0; beq 19f; lwz 3,0x8(30); lis 4,-32705; addi 4,4,-23808; bl _s80182990_19; b 9b; 11:; lwz 3,0x8(30); lis 4,-32705; addi 4,4,-23796; li 5,2; bl _s80182990_20; cmpwi 3,0; beq 19f; lwz 3,0x8(30); lis 4,-32705; addi 4,4,-23792; li 5,2; bl _s80182990_21; cmpwi 3,0; beq 19f; lis 4,-32705; lwz 3,0x8(30); addi 4,4,-23788; li 5,2; bl _s80182990_22; b 19f; 12:; lwz 3,0x8(30); lis 4,-32705; addi 4,4,-23784; li 5,2; bl _s80182990_23; cmpwi 3,0; bne 18f; lwz 3,0x8(30); bl _s80182990_24; cmpwi 3,10; beq 19f; b 18f; 13:; lwz 3,0x8(30); lis 4,-32705; addi 4,4,-23784; li 5,2; bl _s80182990_25; cmpwi 3,0; bne 18f; lwz 3,0x8(30); bl _s80182990_26; cmpwi 3,4; beq 19f; b 18f; 14:; lwz 3,0x8(30); bl _s80182990_27; b 19f; 15:; lwz 3,0x8(30); lis 4,-32705; addi 4,4,-23780; bl _s80182990_28; cmpwi 3,0; beq 19f; lwz 3,0x8(30); lis 4,-32705; addi 4,4,-23772; bl _s80182990_29; cmpwi 3,0; beq 19f; lwz 3,0x8(30); lis 4,-32705; addi 4,4,-23764; bl _s80182990_30; b 9b; 16:; lwz 3,0x8(30); lis 4,-32705; addi 4,4,-23756; bl _s80182990_31; cmpwi 3,0; beq 19f; lwz 3,0x8(30); lis 4,-32705; addi 4,4,-23748; bl _s80182990_32; cmpwi 3,0; beq 19f; lwz 3,0x8(30); lis 4,-32705; addi 4,4,-23740; bl _s80182990_33; cmpwi 3,0; beq 19f; lwz 3,0x8(30); lis 4,-32705; addi 4,4,-23728; bl _s80182990_34; b 9b; 17:; lwz 3,0x8(30); bl _s80182990_35; cmplwi 3,1; ble 19f; 18:; li 25,0; 19:; mr 3,25; lwz 0,0x34(1); mtspr 8,0; lmw 24,0x10(1); addi 1,1,48"
extern "C" void _s80182990_0();
extern "C" void _s80182990_1();
extern "C" void _s80182990_2();
extern "C" void _s80182990_3();
extern "C" void _s80182990_4();
extern "C" void _s80182990_5();
extern "C" void _s80182990_6();
extern "C" void _s80182990_7();
extern "C" void _s80182990_8();
extern "C" void _s80182990_9();
extern "C" void _s80182990_10();
extern "C" void _s80182990_11();
extern "C" void _s80182990_12();
extern "C" void _s80182990_13();
extern "C" void _s80182990_14();
extern "C" void _s80182990_15();
extern "C" void _s80182990_16();
extern "C" void _s80182990_17();
extern "C" void _s80182990_18();
extern "C" void _s80182990_19();
extern "C" void _s80182990_20();
extern "C" void _s80182990_21();
extern "C" void _s80182990_22();
extern "C" void _s80182990_23();
extern "C" void _s80182990_24();
extern "C" void _s80182990_25();
extern "C" void _s80182990_26();
extern "C" void _s80182990_27();
extern "C" void _s80182990_28();
extern "C" void _s80182990_29();
extern "C" void _s80182990_30();
extern "C" void _s80182990_31();
extern "C" void _s80182990_32();
extern "C" void _s80182990_33();
extern "C" void _s80182990_34();
extern "C" void _s80182990_35();
extern "C" void f_80182990() {}
