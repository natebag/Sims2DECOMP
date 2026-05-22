// 0x800B4A1C CTilePt::IsoCompare(CTilePt (124 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 31,3; mr 29,4; bl _s800B4A1C_0; mr 30,3; mr 3,29; bl _s800B4A1C_1; cmpw 30,3; beq 0f; mr 3,31; bl _s800B4A1C_2; mr 30,3; mr 3,29; bl _s800B4A1C_3; b 1f; 0:; mr 3,31; bl _s800B4A1C_4; mr 30,3; mr 3,29; bl _s800B4A1C_5; 1:; cmpw cr7,30,3; mfcr 3; rlwinm 3,3,29,31,31; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s800B4A1C_0();
extern "C" void _s800B4A1C_1();
extern "C" void _s800B4A1C_2();
extern "C" void _s800B4A1C_3();
extern "C" void _s800B4A1C_4();
extern "C" void _s800B4A1C_5();
extern "C" void f_800B4A1C() {}
