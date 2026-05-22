// 0x800034C0 {anonymous}::OverrideMotionBlurSettingsFromTokens(FrameEffectsMotionBlurDataElement (280 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 26,0x8(1); stw 0,0x24(1); mr 28,5; mr 30,3; mr 3,4; li 29,0; addic. 0,28,-1; ble 6f; mr 31,3; lis 26,-32707; lis 27,-32707; 0:; mr 3,31; addi 4,26,-21116; bl _s800034C0_0; cmpwi 3,0; bne 1f; lwz 3,0x4(31); bl _s800034C0_1; stfs f1,0x0(30); b 5f; 1:; mr 3,31; addi 4,27,-21104; bl _s800034C0_2; cmpwi 3,0; bne 2f; lwz 3,0x4(31); bl _s800034C0_3; stfs f1,0x4(30); b 5f; 2:; lis 4,-32707; mr 3,31; addi 4,4,-21076; bl _s800034C0_4; cmpwi 3,0; bne 3f; lwz 3,0x4(31); bl _s800034C0_5; stw 3,0x8(30); b 5f; 3:; lis 4,-32707; mr 3,31; addi 4,4,-21060; bl _s800034C0_6; cmpwi 3,0; bne 4f; lwz 3,0x4(31); bl _s800034C0_7; stfs f1,0xc(30); b 5f; 4:; lis 4,-32707; mr 3,31; addi 4,4,-21048; bl _s800034C0_8; cmpwi 3,0; bne 5f; lwz 3,0x4(31); bl _s800034C0_9; stfs f1,0x10(30); 5:; addi 29,29,2; addi 0,28,-1; cmpw 29,0; addi 31,31,8; blt 0b; 6:; lwz 0,0x24(1); mtspr 8,0; lmw 26,0x8(1); addi 1,1,32"
extern "C" void _s800034C0_0();
extern "C" void _s800034C0_1();
extern "C" void _s800034C0_2();
extern "C" void _s800034C0_3();
extern "C" void _s800034C0_4();
extern "C" void _s800034C0_5();
extern "C" void _s800034C0_6();
extern "C" void _s800034C0_7();
extern "C" void _s800034C0_8();
extern "C" void _s800034C0_9();
extern "C" void f_800034C0() {}
