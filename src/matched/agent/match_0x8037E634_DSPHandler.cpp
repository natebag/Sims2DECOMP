// 0x8037E634 __DSPHandler (1060 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; lis 3,-13312; stw 0,0x4(1); addi 3,3,20480; li 0,-41; stwu 1,-744(1); stw 31,0x2e4(1); addi 31,4,0; lhz 5,0xa(3); and 0,5,0; ori 0,0,128; sth 0,0xa(3); addi 3,1,16; bl _s8037E634_0; addi 3,1,16; bl _s8037E634_1; 0:; bl _s8037E634_2; cmplwi 3,0; beq 0b; bl _s8037E634_3; lwz 5,-22016(13); lwz 0,0x8(5); rlwinm. 0,0,0,30,30; beq 1f; addis 0,3,9007; cmplwi 0,2; bne 1f; lis 3,-9007; addi 3,3,3; 1:; lis 4,-9007; addi 0,4,2; cmpw 3,0; beq 5f; bge 2f; cmpw 3,4; beq 3f; bge 4f; b 28f; 2:; addi 0,4,4; cmpw 3,0; beq 27f; bge 28f; b 15f; 3:; li 0,1; stw 0,0x0(5); lwz 3,-22016(13); lwz 12,0x28(3); cmplwi 12,0; beq 28f; mtspr 8,12; blrl; b 28f; 4:; li 0,1; stw 0,0x0(5); lwz 3,-22016(13); lwz 12,0x2c(3); cmplwi 12,0; beq 28f; mtspr 8,12; blrl; b 28f; 5:; lwz 0,-22036(13); cmpwi 0,0; beq 9f; lwz 0,-22032(13); cmplw 5,0; bne 7f; lis 3,-12847; addi 3,3,3; bl _s8037E634_4; 6:; bl _s8037E634_5; cmplwi 3,0; bne 6b; li 0,0; lwz 3,-22016(13); stw 0,-22032(13); stw 0,-22036(13); lwz 12,0x2c(3); cmplwi 12,0; beq 28f; mtspr 8,12; blrl; b 28f; 7:; lis 3,-12847; addi 3,3,1; bl _s8037E634_6; 8:; bl _s8037E634_7; cmplwi 3,0; bne 8b; lwz 3,-22016(13); lwz 4,-22032(13); bl _s8037E634_8; lwz 3,-22016(13); li 4,2; li 0,0; stw 4,0x0(3); lwz 3,-22032(13); stw 0,-22036(13); stw 3,-22016(13); stw 0,-22032(13); b 28f; 9:; lwz 0,0x38(5); cmplwi 0,0; bne 13f; lwz 0,-22020(13); cmplw 5,0; bne 11f; lis 3,-12847; addi 3,3,3; bl _s8037E634_9; 10:; bl _s8037E634_10; cmplwi 3,0; bne 10b; lwz 3,-22016(13); lwz 12,0x2c(3); cmplwi 12,0; beq 28f; mtspr 8,12; blrl; b 28f; 11:; lis 3,-12847; addi 3,3,1; bl _s8037E634_11; 12:; bl _s8037E634_12; cmplwi 3,0; bne 12b; lwz 3,-22016(13); lwz 4,-22020(13); bl _s8037E634_13; lwz 3,-22016(13); li 0,2; stw 0,0x0(3); lwz 0,-22020(13); stw 0,-22016(13); b 28f; 13:; lis 3,-12847; addi 3,3,1; bl _s8037E634_14; 14:; bl _s8037E634_15; cmplwi 3,0; bne 14b; lwz 3,-22016(13); lwz 4,0x38(3); bl _s8037E634_16; lwz 3,-22016(13); li 0,2; stw 0,0x0(3); lwz 3,-22016(13); lwz 0,0x38(3); stw 0,-22016(13); b 28f; 15:; lwz 0,-22036(13); cmpwi 0,0; beq 18f; lwz 12,0x30(5); cmplwi 12,0; beq 16f; mtspr 8,12; addi 3,5,0; blrl; 16:; lis 3,-12847; addi 3,3,1; bl _s8037E634_17; 17:; bl _s8037E634_18; cmplwi 3,0; bne 17b; li 3,0; lwz 4,-22032(13); bl _s8037E634_19; lwz 3,-22016(13); bl _s8037E634_20; lwz 3,-22032(13); li 0,0; stw 0,-22036(13); stw 3,-22016(13); stw 0,-22032(13); b 28f; 18:; lwz 0,0x38(5); cmplwi 0,0; bne 24f; lwz 0,-22020(13); cmplw 5,0; bne 21f; lwz 12,0x30(5); cmplwi 12,0; beq 19f; mtspr 8,12; addi 3,5,0; blrl; 19:; lis 3,-12847; addi 3,3,2; bl _s8037E634_21; 20:; bl _s8037E634_22; cmplwi 3,0; bne 20b; lwz 3,-22016(13); li 0,3; stw 0,0x0(3); lwz 3,-22016(13); bl _s8037E634_23; b 28f; 21:; lwz 12,0x30(5); cmplwi 12,0; beq 22f; mtspr 8,12; addi 3,5,0; blrl; 22:; lis 3,-12847; addi 3,3,1; bl _s8037E634_24; 23:; bl _s8037E634_25; cmplwi 3,0; bne 23b; lwz 4,-22016(13); li 0,3; li 3,0; stw 0,0x0(4); lwz 4,-22020(13); bl _s8037E634_26; lwz 0,-22020(13); lwz 3,-22024(13); stw 0,-22016(13); bl _s8037E634_27; b 28f; 24:; lwz 12,0x30(5); cmplwi 12,0; beq 25f; mtspr 8,12; addi 3,5,0; blrl; 25:; lis 3,-12847; addi 3,3,1; bl _s8037E634_28; 26:; bl _s8037E634_29; cmplwi 3,0; bne 26b; lwz 4,-22016(13); li 0,3; li 3,0; stw 0,0x0(4); lwz 4,-22016(13); lwz 4,0x38(4); bl _s8037E634_30; lwz 3,-22016(13); lwz 0,0x38(3); stw 0,-22016(13); lwz 3,-22016(13); lwz 3,0x3c(3); bl _s8037E634_31; b 28f; 27:; lwz 12,0x34(5); cmplwi 12,0; beq 28f; mtspr 8,12; addi 3,5,0; blrl; 28:; addi 3,1,16; bl _s8037E634_32; mr 3,31; bl _s8037E634_33; lwz 0,0x2ec(1); lwz 31,0x2e4(1); addi 1,1,744; mtspr 8,0"
extern "C" void _s8037E634_0();
extern "C" void _s8037E634_1();
extern "C" void _s8037E634_2();
extern "C" void _s8037E634_3();
extern "C" void _s8037E634_4();
extern "C" void _s8037E634_5();
extern "C" void _s8037E634_6();
extern "C" void _s8037E634_7();
extern "C" void _s8037E634_8();
extern "C" void _s8037E634_9();
extern "C" void _s8037E634_10();
extern "C" void _s8037E634_11();
extern "C" void _s8037E634_12();
extern "C" void _s8037E634_13();
extern "C" void _s8037E634_14();
extern "C" void _s8037E634_15();
extern "C" void _s8037E634_16();
extern "C" void _s8037E634_17();
extern "C" void _s8037E634_18();
extern "C" void _s8037E634_19();
extern "C" void _s8037E634_20();
extern "C" void _s8037E634_21();
extern "C" void _s8037E634_22();
extern "C" void _s8037E634_23();
extern "C" void _s8037E634_24();
extern "C" void _s8037E634_25();
extern "C" void _s8037E634_26();
extern "C" void _s8037E634_27();
extern "C" void _s8037E634_28();
extern "C" void _s8037E634_29();
extern "C" void _s8037E634_30();
extern "C" void _s8037E634_31();
extern "C" void _s8037E634_32();
extern "C" void _s8037E634_33();
extern "C" void f_8037E634() {}
