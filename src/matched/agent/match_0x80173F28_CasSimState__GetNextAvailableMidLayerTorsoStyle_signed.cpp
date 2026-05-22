// 0x80173F28 CasSimState::GetNextAvailableMidLayerTorsoStyle(signed (208 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-72(1); mfspr 0,8; stmw 24,0x28(1); stw 0,0x4c(1); mr 27,3; mr 26,5; mr 24,4; addi 3,1,8; mr 25,6; addi 4,27,8; li 5,9; bl _s80173F28_0; lwz 29,0xc(1); mr 3,27; mr 5,26; mr 4,29; bl _s80173F28_1; mr 31,3; cmpw 29,31; beq 1f; addi 30,1,24; addi 28,1,8; 0:; stw 31,0xc(1); mr 3,25; lwz 10,0x8(1); li 4,9; lwz 11,0x4(28); mr 5,24; lwz 9,0x8(28); mr 6,30; lwz 0,0xc(28); stw 10,0x18(1); stw 11,0x4(30); stw 9,0x8(30); stw 0,0xc(30); bl _s80173F28_2; cmpwi 3,0; mr 3,31; bne 2f; mr 4,31; mr 3,27; mr 5,26; bl _s80173F28_3; mr 31,3; cmpw 29,31; bne 0b; 1:; mr 3,31; 2:; lwz 0,0x4c(1); mtspr 8,0; lmw 24,0x28(1); addi 1,1,72"
extern "C" void _s80173F28_0();
extern "C" void _s80173F28_1();
extern "C" void _s80173F28_2();
extern "C" void _s80173F28_3();
extern "C" void f_80173F28() {}
