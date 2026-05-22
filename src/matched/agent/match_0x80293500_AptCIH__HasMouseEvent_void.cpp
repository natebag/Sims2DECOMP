// 0x80293500 AptCIH::HasMouseEvent(void) (40 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); lis 4,9; ori 4,4,64568; bl _s80293500_0; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s80293500_0();
extern "C" void f_80293500() {}
