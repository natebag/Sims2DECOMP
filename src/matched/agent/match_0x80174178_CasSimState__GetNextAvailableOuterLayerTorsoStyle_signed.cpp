// 0x80174178 CasSimState::GetNextAvailableOuterLayerTorsoStyle(signed (212 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-72(1); mfspr 0,8; stmw 25,0x2c(1); stw 0,0x4c(1); mr 27,3; mr 25,4; mr 26,5; addi 3,1,8; addi 4,27,8; li 5,12; bl _s80174178_0; lwz 29,0xc(1); mr 3,27; li 5,2; li 6,1; mr 4,29; bl _s80174178_1; mr 31,3; cmpw 29,31; beq 1f; addi 30,1,24; addi 28,1,8; 0:; stw 31,0xc(1); mr 3,26; lwz 10,0x8(1); li 4,12; lwz 11,0x4(28); mr 5,25; lwz 9,0x8(28); mr 6,30; lwz 0,0xc(28); stw 10,0x18(1); stw 11,0x4(30); stw 9,0x8(30); stw 0,0xc(30); bl _s80174178_2; cmpwi 3,0; mr 3,31; bne 2f; mr 4,31; mr 3,27; li 5,2; li 6,1; bl _s80174178_3; mr 31,3; cmpw 29,31; bne 0b; 1:; mr 3,31; 2:; lwz 0,0x4c(1); mtspr 8,0; lmw 25,0x2c(1); addi 1,1,72"
extern "C" void _s80174178_0();
extern "C" void _s80174178_1();
extern "C" void _s80174178_2();
extern "C" void _s80174178_3();
extern "C" void f_80174178() {}
