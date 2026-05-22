// 0x80170394 CasSimRendererDynamic::SelectNextStandingAnimation(void) (880 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 31,3; li 4,1; addi 3,31,372; bl _s80170394_0; mr 30,3; lwz 29,0x218(31); mr 3,31; mr 4,30; bl _s80170394_1; cmpwi 3,0; beq 1f; mr 4,29; mr 3,31; bl _s80170394_2; cmpwi 3,0; beq 0f; lwz 0,0x228(31); cmpwi 0,0; beq 16f; bl _s80170394_3; andi. 0,3,1; bne 16f; lwz 9,0x224(31); mr 3,31; lwz 4,0x60(9); bl _s80170394_4; b 22f; 0:; lwz 9,0x224(31); mr 3,31; lwz 4,0x34(9); bl _s80170394_5; b 22f; 1:; mr 3,31; mr 4,30; bl _s80170394_6; cmpwi 3,0; beq 5f; mr 4,29; mr 3,31; bl _s80170394_7; cmpwi 3,0; beq 4f; lwz 0,0x22c(31); cmpwi 0,0; beq 3f; bl _s80170394_8; andi. 0,3,1; bne 3f; bl _s80170394_9; andi. 0,3,1; bne 2f; lwz 9,0x224(31); lwz 4,0x58(9); b 20f; 2:; lwz 9,0x224(31); lwz 4,0x5c(9); b 20f; 3:; lwz 9,0x224(31); mr 3,31; lwz 4,0x1c(9); bl _s80170394_10; b 22f; 4:; lwz 9,0x224(31); mr 3,31; lwz 4,0x20(9); bl _s80170394_11; b 22f; 5:; mr 3,31; mr 4,30; bl _s80170394_12; cmpwi 3,0; beq 8f; mr 4,29; mr 3,31; bl _s80170394_13; cmpwi 3,0; beq 7f; lwz 0,0x230(31); cmpwi 0,0; beq 6f; bl _s80170394_14; andi. 0,3,1; bne 6f; lwz 9,0x224(31); mr 3,31; lwz 4,0x64(9); bl _s80170394_15; b 22f; 6:; lwz 9,0x224(31); mr 3,31; lwz 4,0x3c(9); bl _s80170394_16; b 22f; 7:; lwz 9,0x224(31); mr 3,31; lwz 4,0x40(9); bl _s80170394_17; b 22f; 8:; lwz 9,0x224(31); lwz 0,0x34(9); cmpw 30,0; beq 9f; lwz 0,0x20(9); cmpw 30,0; beq 9f; lwz 0,0x40(9); cmpw 30,0; beq 9f; lwz 0,0x14(9); cmpw 30,0; beq 9f; lwz 0,0x48(9); cmpw 30,0; beq 9f; mr 3,31; mr 4,30; bl _s80170394_18; cmpwi 3,0; beq 14f; 9:; mr 3,31; mr 4,29; bl _s80170394_19; cmpwi 3,0; bne 12f; mr 3,31; mr 4,29; bl _s80170394_20; cmpwi 3,0; beq 10f; lwz 9,0x224(31); mr 3,31; lwz 4,0x24(9); bl _s80170394_21; b 22f; 10:; lwz 9,0x224(31); lwz 0,0x1c(9); cmpw 29,0; bne 11f; lwz 4,0x18(9); b 20f; 11:; lwz 0,0x3c(9); cmpw 29,0; bne 22f; lwz 4,0x38(9); b 20f; 12:; lwz 0,0x234(31); cmpwi 0,0; beq 13f; lwz 4,0x238(31); mr 3,31; bl _s80170394_22; lwz 9,0x238(31); li 0,0; stw 0,0x234(31); stw 9,0x218(31); b 22f; 13:; lwz 0,0x220(31); cmpwi 0,0; beq 21f; bl _s80170394_23; lis 0,26214; srawi 9,3,31; ori 0,0,26215; mulhw 0,3,0; srawi 0,0,3; subf 0,9,0; mulli 0,0,20; cmpw 3,0; bne 21f; lwz 9,0x224(31); mr 3,31; lwz 4,0xc(9); bl _s80170394_24; b 22f; 14:; lwz 9,0x224(31); lwz 0,0xc(9); cmpw 30,0; bne 15f; lwz 4,0x10(9); b 20f; 15:; lwz 0,0x24(9); cmpw 30,0; bne 17f; 16:; mr 3,31; bl _s80170394_25; b 22f; 17:; lwz 0,0x18(9); cmpw 30,0; bne 18f; lwz 4,0x1c(9); b 20f; 18:; lwz 0,0x38(9); cmpw 30,0; bne 19f; lwz 4,0x3c(9); b 20f; 19:; lwz 0,0x10(9); cmpw 30,0; bne 21f; lwz 4,0x14(9); 20:; mr 3,31; bl _s80170394_26; b 22f; 21:; mr 3,31; bl _s80170394_27; stw 3,0x218(31); 22:; li 0,0; stw 0,0x234(31); stw 0,0x228(31); stw 0,0x22c(31); stw 0,0x230(31); lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s80170394_0();
extern "C" void _s80170394_1();
extern "C" void _s80170394_2();
extern "C" void _s80170394_3();
extern "C" void _s80170394_4();
extern "C" void _s80170394_5();
extern "C" void _s80170394_6();
extern "C" void _s80170394_7();
extern "C" void _s80170394_8();
extern "C" void _s80170394_9();
extern "C" void _s80170394_10();
extern "C" void _s80170394_11();
extern "C" void _s80170394_12();
extern "C" void _s80170394_13();
extern "C" void _s80170394_14();
extern "C" void _s80170394_15();
extern "C" void _s80170394_16();
extern "C" void _s80170394_17();
extern "C" void _s80170394_18();
extern "C" void _s80170394_19();
extern "C" void _s80170394_20();
extern "C" void _s80170394_21();
extern "C" void _s80170394_22();
extern "C" void _s80170394_23();
extern "C" void _s80170394_24();
extern "C" void _s80170394_25();
extern "C" void _s80170394_26();
extern "C" void _s80170394_27();
extern "C" void f_80170394() {}
