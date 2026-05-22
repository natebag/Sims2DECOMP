// 0x800035D8 {anonymous}::OverrideBloomSettingsFromTokens(FrameEffectsBloomDataElement (600 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); mr 28,5; mr 30,3; mr 3,4; li 29,0; addic. 0,28,-1; ble 14f; mr 31,3; 0:; lis 4,-32707; mr 3,31; addi 4,4,-21036; bl _s800035D8_0; cmpwi 3,0; bne 1f; lwz 3,0x4(31); bl _s800035D8_1; stfs f1,0x0(30); b 13f; 1:; lis 4,-32707; mr 3,31; addi 4,4,-21024; bl _s800035D8_2; cmpwi 3,0; bne 2f; lwz 3,0x4(31); bl _s800035D8_3; stfs f1,0x4(30); b 13f; 2:; lis 4,-32707; mr 3,31; addi 4,4,-21008; bl _s800035D8_4; cmpwi 3,0; bne 3f; lwz 3,0x4(31); bl _s800035D8_5; stfs f1,0x8(30); b 13f; 3:; lis 4,-32707; mr 3,31; addi 4,4,-20996; bl _s800035D8_6; cmpwi 3,0; bne 4f; lwz 3,0x4(31); bl _s800035D8_7; stfs f1,0xc(30); b 13f; 4:; lis 4,-32707; mr 3,31; addi 4,4,-20976; bl _s800035D8_8; cmpwi 3,0; bne 5f; lwz 3,0x4(31); bl _s800035D8_9; stfs f1,0x10(30); b 13f; 5:; lis 4,-32707; mr 3,31; addi 4,4,-20956; bl _s800035D8_10; cmpwi 3,0; bne 6f; lwz 3,0x4(31); bl _s800035D8_11; stfs f1,0x14(30); b 13f; 6:; lis 4,-32707; mr 3,31; addi 4,4,-20936; bl _s800035D8_12; cmpwi 3,0; bne 7f; lwz 3,0x4(31); bl _s800035D8_13; stfs f1,0x18(30); b 13f; 7:; lis 4,-32707; mr 3,31; addi 4,4,-20916; bl _s800035D8_14; cmpwi 3,0; bne 8f; lwz 3,0x4(31); bl _s800035D8_15; stfs f1,0x1c(30); b 13f; 8:; lis 4,-32707; mr 3,31; addi 4,4,-20896; bl _s800035D8_16; cmpwi 3,0; bne 9f; lwz 3,0x4(31); bl _s800035D8_17; stfs f1,0x20(30); b 13f; 9:; lis 4,-32707; mr 3,31; addi 4,4,-20876; bl _s800035D8_18; cmpwi 3,0; bne 10f; lwz 3,0x4(31); bl _s800035D8_19; stfs f1,0x24(30); b 13f; 10:; lis 4,-32707; mr 3,31; addi 4,4,-20856; bl _s800035D8_20; cmpwi 3,0; bne 11f; lwz 3,0x4(31); bl _s800035D8_21; stfs f1,0x28(30); b 13f; 11:; lis 4,-32707; mr 3,31; addi 4,4,-21060; bl _s800035D8_22; cmpwi 3,0; bne 12f; lwz 3,0x4(31); bl _s800035D8_23; stfs f1,0x2c(30); b 13f; 12:; lis 4,-32707; mr 3,31; addi 4,4,-21048; bl _s800035D8_24; cmpwi 3,0; bne 13f; lwz 3,0x4(31); bl _s800035D8_25; stfs f1,0x30(30); 13:; addi 29,29,2; addi 0,28,-1; cmpw 29,0; addi 31,31,8; blt 0b; 14:; lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"
extern "C" void _s800035D8_0();
extern "C" void _s800035D8_1();
extern "C" void _s800035D8_2();
extern "C" void _s800035D8_3();
extern "C" void _s800035D8_4();
extern "C" void _s800035D8_5();
extern "C" void _s800035D8_6();
extern "C" void _s800035D8_7();
extern "C" void _s800035D8_8();
extern "C" void _s800035D8_9();
extern "C" void _s800035D8_10();
extern "C" void _s800035D8_11();
extern "C" void _s800035D8_12();
extern "C" void _s800035D8_13();
extern "C" void _s800035D8_14();
extern "C" void _s800035D8_15();
extern "C" void _s800035D8_16();
extern "C" void _s800035D8_17();
extern "C" void _s800035D8_18();
extern "C" void _s800035D8_19();
extern "C" void _s800035D8_20();
extern "C" void _s800035D8_21();
extern "C" void _s800035D8_22();
extern "C" void _s800035D8_23();
extern "C" void _s800035D8_24();
extern "C" void _s800035D8_25();
extern "C" void f_800035D8() {}
