// 0x802402B0 ForceDvdTcIrq (136 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 30,3; bl _s802402B0_0; lis 9,-13312; lis 0,4608; ori 9,9,24584; lis 11,-13312; stw 0,0x0(9); ori 11,11,24588; li 0,0; lis 10,-13312; stw 0,0x0(11); li 8,32; ori 10,10,24592; lis 9,-13312; stw 8,0x0(10); ori 9,9,24600; stw 8,0x0(9); lis 11,-13312; ori 11,11,24596; lis 9,-13312; stw 30,0x0(11); ori 9,9,24604; li 0,3; stw 0,0x0(9); bl _s802402B0_1; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s802402B0_0();
extern "C" void _s802402B0_1();
extern "C" void f_802402B0() {}
