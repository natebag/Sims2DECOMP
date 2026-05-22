// 0x80262700 ImportAdjustingValues (60 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-8(1); bl _s80262700_0; lbz 4,0x10(3); li 0,0; li 3,0; extsb 4,4; sth 0,-23250(13); sth 4,-23252(13); bl _s80262700_1; lwz 0,0xc(1); addi 1,1,8; mtspr 8,0"
extern "C" void _s80262700_0();
extern "C" void _s80262700_1();
extern "C" void f_80262700() {}
