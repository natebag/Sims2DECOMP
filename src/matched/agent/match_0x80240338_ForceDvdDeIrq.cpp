// 0x80240338 ForceDvdDeIrq (68 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); bl _s80240338_0; lis 9,-13312; li 0,0; ori 9,9,24584; lis 11,-13312; stw 0,0x0(9); ori 11,11,24604; li 0,1; stw 0,0x0(11); bl _s80240338_1; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s80240338_0();
extern "C" void _s80240338_1();
extern "C" void f_80240338() {}
