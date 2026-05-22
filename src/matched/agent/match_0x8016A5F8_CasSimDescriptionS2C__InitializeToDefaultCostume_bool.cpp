// 0x8016A5F8 CasSimDescriptionS2C::InitializeToDefaultCostume(bool) (120 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 30,4; mr 31,3; li 4,0; bl _s8016A5F8_0; cmpwi 30,0; beq 0f; li 9,1; li 11,3; li 10,8; li 0,9; stb 0,0xcc(31); stw 9,0x84(31); stb 11,0x98(31); stb 10,0xc4(31); b 1f; 0:; li 9,4; li 0,7; stb 9,0xcc(31); stw 30,0x84(31); stb 0,0xc4(31); stb 9,0x98(31); 1:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s8016A5F8_0();
extern "C" void f_8016A5F8() {}
