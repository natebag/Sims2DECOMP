// 0x801B8D0C H2DTarget::SpawnIntroThoughtBalloon(UIDialog (84 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 31,3; mr 30,4; lwz 0,0xc4(31); cmpwi 0,0; bne 0f; li 3,160; bl _s801B8D0C_0; bl _s801B8D0C_1; stw 3,0xc4(31); 0:; lwz 3,0xc4(31); mr 4,30; bl _s801B8D0C_2; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s801B8D0C_0();
extern "C" void _s801B8D0C_1();
extern "C" void _s801B8D0C_2();
extern "C" void f_801B8D0C() {}
