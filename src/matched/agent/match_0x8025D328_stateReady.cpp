// 0x8025D328 stateReady (744 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; lis 3,-32694; stw 0,0x4(1); stwu 1,-16(1); stw 31,0xc(1); addi 31,3,-17248; bl _s8025D328_0; cmpwi 3,0; bne 0f; li 0,0; stw 0,-23480(13); b 21f; 0:; lwz 0,-23468(13); cmpwi 0,0; beq 1f; li 3,1; li 0,0; stw 3,-23464(13); stw 0,-23480(13); b 21f; 1:; bl _s8025D328_1; lwz 0,-23456(13); stw 3,-23480(13); cmpwi 0,0; beq 3f; lwz 3,-23480(13); li 4,-1; addi 0,31,64; stw 4,0xc(3); lwz 4,-23480(13); stw 0,-23480(13); lwz 12,0x28(4); cmplwi 12,0; beq 2f; mtspr 8,12; li 3,-1; blrl; 2:; bl _s8025D328_2; b 21f; 3:; lwz 4,-23480(13); lwz 0,0x8(4); stw 0,-23452(13); lwz 0,-23440(13); cmplwi 0,0; beq 15f; lwz 0,-23440(13); cmpwi 0,4; beq 7f; bge 4f; cmpwi 0,2; beq 5f; bge 6f; cmpwi 0,1; bge 8f; b 14f; 4:; cmpwi 0,8; bge 14f; cmpwi 0,6; bge 8f; b 13f; 5:; li 0,11; lis 3,-32730; stw 0,0xc(4); addi 3,3,-11716; bl _s8025D328_3; b 14f; 6:; li 0,4; lis 3,-32730; stw 0,0xc(4); addi 3,3,-11716; bl _s8025D328_4; b 14f; 7:; li 0,5; lis 3,-32730; stw 0,0xc(4); addi 3,3,-11716; bl _s8025D328_5; b 14f; 8:; li 0,3; stw 0,0xc(4); lwz 0,-23452(13); cmpwi 0,13; beq 10f; bge 9f; cmpwi 0,6; bge 12f; cmpwi 0,4; bge 10f; b 12f; 9:; cmpwi 0,15; beq 10f; b 12f; 10:; bl _s8025D328_6; lwz 4,-23480(13); addi 0,31,64; stw 0,-23480(13); lwz 12,0x28(4); cmplwi 12,0; beq 11f; mtspr 8,12; li 3,-4; blrl; 11:; bl _s8025D328_7; b 14f; 12:; li 0,0; stw 0,-23408(13); bl _s8025D328_8; addi 3,31,112; bl _s8025D328_9; lis 3,-32768; lwz 0,0xf8(3); lis 4,4194; lis 3,-32730; rlwinm 0,0,30,2,31; addi 4,4,19923; mulhwu 0,4,0; rlwinm 0,0,26,6,31; mulli 6,0,1150; addi 7,3,-12184; addi 3,31,112; li 5,0; bl _s8025D328_10; b 14f; 13:; lwz 3,-23436(13); bl _s8025D328_11; lis 3,-32730; addi 3,3,-15216; bl _s8025D328_12; 14:; li 0,0; stw 0,-23440(13); b 21f; 15:; lwz 0,-23408(13); cmplwi 0,0; bne 16f; li 0,1; stw 0,0xc(4); lwz 3,-23480(13); bl _s8025D328_13; b 21f; 16:; lwz 0,-23452(13); cmpwi 0,13; beq 18f; bge 17f; cmpwi 0,6; bge 20f; cmpwi 0,4; bge 18f; b 20f; 17:; cmpwi 0,15; beq 18f; b 20f; 18:; bl _s8025D328_14; lwz 4,-23480(13); addi 0,31,64; stw 0,-23480(13); lwz 12,0x28(4); cmplwi 12,0; beq 19f; mtspr 8,12; li 3,-4; blrl; 19:; bl _s8025D328_15; b 21f; 20:; li 0,0; stw 0,-23408(13); bl _s8025D328_16; addi 3,31,112; bl _s8025D328_17; lis 3,-32768; lwz 0,0xf8(3); lis 4,4194; lis 3,-32730; rlwinm 0,0,30,2,31; addi 4,4,19923; mulhwu 0,4,0; rlwinm 0,0,26,6,31; mulli 6,0,1150; addi 7,3,-12184; addi 3,31,112; li 5,0; bl _s8025D328_18; 21:; lwz 0,0x14(1); lwz 31,0xc(1); addi 1,1,16; mtspr 8,0"
extern "C" void _s8025D328_0();
extern "C" void _s8025D328_1();
extern "C" void _s8025D328_2();
extern "C" void _s8025D328_3();
extern "C" void _s8025D328_4();
extern "C" void _s8025D328_5();
extern "C" void _s8025D328_6();
extern "C" void _s8025D328_7();
extern "C" void _s8025D328_8();
extern "C" void _s8025D328_9();
extern "C" void _s8025D328_10();
extern "C" void _s8025D328_11();
extern "C" void _s8025D328_12();
extern "C" void _s8025D328_13();
extern "C" void _s8025D328_14();
extern "C" void _s8025D328_15();
extern "C" void _s8025D328_16();
extern "C" void _s8025D328_17();
extern "C" void _s8025D328_18();
extern "C" void f_8025D328() {}
