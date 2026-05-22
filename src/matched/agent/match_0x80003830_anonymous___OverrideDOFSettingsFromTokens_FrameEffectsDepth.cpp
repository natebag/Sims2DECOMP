// 0x80003830 {anonymous}::OverrideDOFSettingsFromTokens(FrameEffectsDepthOfFieldDataElement (360 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); mr 28,5; mr 30,3; mr 3,4; li 29,0; addic. 0,28,-1; ble 8f; mr 31,3; 0:; lis 4,-32707; mr 3,31; addi 4,4,-21076; bl _s80003830_0; cmpwi 3,0; bne 1f; lwz 3,0x4(31); bl _s80003830_1; stw 3,0x0(30); b 7f; 1:; lis 4,-32707; mr 3,31; addi 4,4,-20836; bl _s80003830_2; cmpwi 3,0; bne 2f; lwz 3,0x4(31); bl _s80003830_3; stfs f1,0x4(30); b 7f; 2:; lis 4,-32707; mr 3,31; addi 4,4,-20828; bl _s80003830_4; cmpwi 3,0; bne 3f; lwz 3,0x4(31); bl _s80003830_5; stfs f1,0x8(30); b 7f; 3:; lis 4,-32707; mr 3,31; addi 4,4,-20820; bl _s80003830_6; cmpwi 3,0; bne 4f; lwz 3,0x4(31); bl _s80003830_7; stfs f1,0xc(30); b 7f; 4:; lis 4,-32707; mr 3,31; addi 4,4,-20812; bl _s80003830_8; cmpwi 3,0; bne 5f; lwz 3,0x4(31); bl _s80003830_9; stfs f1,0x10(30); b 7f; 5:; lis 4,-32707; mr 3,31; addi 4,4,-21060; bl _s80003830_10; cmpwi 3,0; bne 6f; lwz 3,0x4(31); bl _s80003830_11; stfs f1,0x14(30); b 7f; 6:; lis 4,-32707; mr 3,31; addi 4,4,-21048; bl _s80003830_12; cmpwi 3,0; bne 7f; lwz 3,0x4(31); bl _s80003830_13; stfs f1,0x18(30); 7:; addi 29,29,2; addi 0,28,-1; cmpw 29,0; addi 31,31,8; blt 0b; 8:; lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"
extern "C" void _s80003830_0();
extern "C" void _s80003830_1();
extern "C" void _s80003830_2();
extern "C" void _s80003830_3();
extern "C" void _s80003830_4();
extern "C" void _s80003830_5();
extern "C" void _s80003830_6();
extern "C" void _s80003830_7();
extern "C" void _s80003830_8();
extern "C" void _s80003830_9();
extern "C" void _s80003830_10();
extern "C" void _s80003830_11();
extern "C" void _s80003830_12();
extern "C" void _s80003830_13();
extern "C" void f_80003830() {}
