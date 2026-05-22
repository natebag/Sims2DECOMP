// 0x8029EE74 AptLinker::SwapOut(AptSharedPtr<AptFile>, (1076 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-88(1); mfspr 0,8; stmw 26,0x40(1); stw 0,0x5c(1); mr 27,5; mr 29,3; lwz 3,0x0(27); mr 26,4; addi 31,1,8; stw 3,0x8(1); cmpwi 3,0; beq 0f; bl _s8029EE74_0; 0:; mr 3,29; mr 4,31; bl _s8029EE74_1; lwz 3,0x0(26); stw 3,0x18(1); cmpwi 3,0; beq 1f; bl _s8029EE74_2; 1:; lwz 0,0x0(29); addi 8,1,16; stw 0,0x20(1); mr 31,8; b 3f; 2:; lwz 9,0x0(10); lwz 11,0x18(1); lwz 0,0x4(9); cmpw 0,11; beq 18f; lwz 0,0x4(10); stw 0,0x20(1); 3:; li 0,0; lwz 10,0x20(1); stw 0,0x28(1); li 0,1; cmpwi 10,0; bne 4f; li 0,0; 4:; cmpwi 0,0; bne 2b; stw 0,0x0(8); 5:; lwz 3,0x18(1); cmpwi 3,0; beq 6f; bl _s8029EE74_3; cmpwi 3,0; bne 6f; lwz 3,0x18(1); bl _s8029EE74_4; 6:; lwz 9,0x10(1); lwz 3,0x0(9); stw 3,0x8(1); cmpwi 3,0; beq 7f; bl _s8029EE74_5; 7:; lwz 9,0x8(1); li 10,0; lwz 0,0x0(29); lwz 28,0x8(9); b 9f; 8:; lwz 9,0x0(11); lwz 0,0x8(9); cmpw 0,28; beq 17f; lwz 0,0x4(11); 9:; stw 0,0x18(1); lwz 11,0x18(1); li 0,1; stw 10,0x20(1); cmpwi 11,0; bne 10f; li 0,0; 10:; cmpwi 0,0; bne 8b; stw 0,0x0(31); 11:; lwz 30,0x10(1); li 0,0; stw 0,0x18(1); cmpwi 30,0; bne 19f; lwz 3,-23020(13); li 4,16; bl _s8029EE74_6; mr 31,3; lwz 3,0x0(27); stw 3,0x30(1); cmpwi 3,0; beq 12f; bl _s8029EE74_7; 12:; stw 30,0x0(31); lwz 3,0x30(1); stw 3,0x4(31); cmpwi 3,0; beq 13f; bl _s8029EE74_8; 13:; stw 28,0x8(31); stw 30,0xc(31); lwz 3,0x30(1); cmpwi 3,0; beq 14f; bl _s8029EE74_9; cmpwi 3,0; bne 14f; lwz 3,0x30(1); bl _s8029EE74_10; 14:; stw 31,0x20(1); cmpwi 31,0; beq 15f; mr 3,31; bl _s8029EE74_11; 15:; lwz 3,-23020(13); li 4,8; bl _s8029EE74_12; mr 31,3; lwz 3,0x20(1); stw 3,0x0(31); cmpwi 3,0; beq 16f; bl _s8029EE74_13; 16:; li 0,0; stw 0,0x4(31); lwz 9,0x0(29); stw 9,0x4(31); stw 31,0x0(29); lwz 3,0x20(1); cmpwi 3,0; beq 31f; bl _s8029EE74_14; cmpwi 3,0; bne 31f; lwz 3,0x20(1); bl _s8029EE74_15; b 31f; 17:; stw 11,0x10(1); b 11b; 18:; stw 10,0x10(1); b 5b; 19:; lwz 0,0x0(29); cmpw 30,0; bne 21f; lwz 3,0x0(30); lwz 31,0x4(30); cmpwi 3,0; beq 20f; bl _s8029EE74_16; cmpwi 3,0; bne 20f; lwz 3,0x0(30); bl _s8029EE74_17; 20:; lwz 3,-23020(13); mr 4,30; li 5,8; bl _s8029EE74_18; stw 31,0x0(29); b 25f; 21:; mr. 9,0; beq 23f; lwz 0,0x4(9); cmpw 0,30; beq 23f; mr 4,30; 22:; lwz 9,0x4(9); cmpwi 9,0; beq 23f; lwz 0,0x4(9); cmpw 0,4; bne 22b; 23:; lwz 31,0x4(9); cmpwi 31,0; beq 25f; lwz 0,0x4(31); stw 0,0x4(9); beq 25f; lwz 3,0x0(31); cmpwi 3,0; beq 24f; bl _s8029EE74_19; cmpwi 3,0; bne 24f; lwz 3,0x0(31); bl _s8029EE74_20; 24:; lwz 3,-23020(13); mr 4,31; li 5,8; bl _s8029EE74_21; 25:; lwz 3,-23020(13); li 4,16; bl _s8029EE74_22; mr 31,3; lwz 3,0x0(27); stw 3,0x38(1); cmpwi 3,0; beq 26f; bl _s8029EE74_23; 26:; li 30,0; stw 30,0x0(31); lwz 3,0x38(1); stw 3,0x4(31); cmpwi 3,0; beq 27f; bl _s8029EE74_24; 27:; stw 28,0x8(31); stw 30,0xc(31); lwz 3,0x38(1); cmpwi 3,0; beq 28f; bl _s8029EE74_25; cmpwi 3,0; bne 28f; lwz 3,0x38(1); bl _s8029EE74_26; 28:; stw 31,0x20(1); cmpwi 31,0; beq 29f; mr 3,31; bl _s8029EE74_27; 29:; lwz 3,-23020(13); li 4,8; bl _s8029EE74_28; mr 31,3; lwz 3,0x20(1); stw 3,0x0(31); cmpwi 3,0; beq 30f; bl _s8029EE74_29; 30:; li 0,0; stw 0,0x4(31); lwz 9,0x0(29); stw 9,0x4(31); stw 31,0x0(29); lwz 3,0x20(1); cmpwi 3,0; beq 31f; bl _s8029EE74_30; cmpwi 3,0; bne 31f; lwz 3,0x20(1); bl _s8029EE74_31; 31:; lwz 3,0x8(1); cmpwi 3,0; beq 32f; bl _s8029EE74_32; cmpwi 3,0; bne 32f; lwz 3,0x8(1); bl _s8029EE74_33; 32:; lwz 3,0x0(26); cmpwi 3,0; beq 33f; bl _s8029EE74_34; cmpwi 3,0; bne 33f; lwz 3,0x0(26); bl _s8029EE74_35; 33:; lwz 3,0x0(27); cmpwi 3,0; beq 34f; bl _s8029EE74_36; cmpwi 3,0; bne 34f; lwz 3,0x0(27); bl _s8029EE74_37; 34:; lwz 0,0x5c(1); mtspr 8,0; lmw 26,0x40(1); addi 1,1,88"
extern "C" void _s8029EE74_0();
extern "C" void _s8029EE74_1();
extern "C" void _s8029EE74_2();
extern "C" void _s8029EE74_3();
extern "C" void _s8029EE74_4();
extern "C" void _s8029EE74_5();
extern "C" void _s8029EE74_6();
extern "C" void _s8029EE74_7();
extern "C" void _s8029EE74_8();
extern "C" void _s8029EE74_9();
extern "C" void _s8029EE74_10();
extern "C" void _s8029EE74_11();
extern "C" void _s8029EE74_12();
extern "C" void _s8029EE74_13();
extern "C" void _s8029EE74_14();
extern "C" void _s8029EE74_15();
extern "C" void _s8029EE74_16();
extern "C" void _s8029EE74_17();
extern "C" void _s8029EE74_18();
extern "C" void _s8029EE74_19();
extern "C" void _s8029EE74_20();
extern "C" void _s8029EE74_21();
extern "C" void _s8029EE74_22();
extern "C" void _s8029EE74_23();
extern "C" void _s8029EE74_24();
extern "C" void _s8029EE74_25();
extern "C" void _s8029EE74_26();
extern "C" void _s8029EE74_27();
extern "C" void _s8029EE74_28();
extern "C" void _s8029EE74_29();
extern "C" void _s8029EE74_30();
extern "C" void _s8029EE74_31();
extern "C" void _s8029EE74_32();
extern "C" void _s8029EE74_33();
extern "C" void _s8029EE74_34();
extern "C" void _s8029EE74_35();
extern "C" void _s8029EE74_36();
extern "C" void _s8029EE74_37();
extern "C" void f_8029EE74() {}
