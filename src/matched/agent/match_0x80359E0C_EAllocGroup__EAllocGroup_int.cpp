// 0x80359E0C EAllocGroup::EAllocGroup(int) (84 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 30,3; li 9,0; add 11,4,4; li 0,1; stw 9,0x0(30); stw 0,0x8(30); stw 11,0x14(30); stw 9,0x4(30); stw 4,0x10(30); bl _s80359E0C_0; stw 3,0xc(30); mr 3,30; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s80359E0C_0();
extern "C" void f_80359E0C() {}
