// 0x800C02B4 IFFResFile2::GetBlockHeader(IFFHeader (100 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 30,0x10(1); stw 0,0x1c(1); li 0,76; mr 30,4; addi 31,3,16; mr 4,5; stw 0,0x8(1); mr 3,31; bl _s800C02B4_0; mr. 3,3; bne 0f; mr 3,31; mr 4,30; addi 5,1,8; bl _s800C02B4_1; mr. 3,3; bne 0f; li 3,0; 0:; lwz 0,0x1c(1); mtspr 8,0; lmw 30,0x10(1); addi 1,1,24"
extern "C" void _s800C02B4_0();
extern "C" void _s800C02B4_1();
extern "C" void f_800C02B4() {}
