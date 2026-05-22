// 0x80095AD4 TArray<ENLatticePoints, (88 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 3,0x8(3); bl _s80095AD4_0; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8; blr; stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); lwz 3,0x8(3); bl _s80095AD4_1; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8; blr; lwz 9,0x8(3); lwz 3,0x90(9); blr; lwz 9,0x8(3); li 0,0; stw 0,0x90(9)"
extern "C" void _s80095AD4_0();
extern "C" void _s80095AD4_1();
extern "C" void f_80095AD4() {}
