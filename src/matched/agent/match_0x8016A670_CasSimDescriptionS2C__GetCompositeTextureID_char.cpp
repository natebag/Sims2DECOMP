// 0x8016A670 CasSimDescriptionS2C::GetCompositeTextureID(char (92 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 29,0x14(1); stw 0,0x24(1); mr 0,4; mr 6,5; mr 4,3; mr 5,0; addi 3,1,8; mr 29,3; bl _s8016A670_0; lwz 3,0x8(1); bl _s8016A670_1; mr 30,3; lwz 4,0x8(1); mr 3,29; bl _s8016A670_2; mr 3,30; lwz 0,0x24(1); mtspr 8,0; lmw 29,0x14(1); addi 1,1,32"
extern "C" void _s8016A670_0();
extern "C" void _s8016A670_1();
extern "C" void _s8016A670_2();
extern "C" void f_8016A670() {}
