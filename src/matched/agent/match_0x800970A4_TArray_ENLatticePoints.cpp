// 0x800970A4 TArray<ENLatticePoints, (76 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mr 30,3; li 0,1; lwz 3,0x5e80(9); li 4,1; stw 0,-28404(13); stw 0,-28408(13); bl _s800970A4_0; lis 9,-32706; mr 3,30; lfs f1,-29824(9); li 4,2; bl _s800970A4_1; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16; blr; blr"
extern "C" void _s800970A4_0();
extern "C" void _s800970A4_1();
extern "C" void f_800970A4() {}
