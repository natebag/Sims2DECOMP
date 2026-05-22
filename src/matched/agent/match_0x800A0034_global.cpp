// 0x800A0034 global (44 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); li 4,0; li 3,1; ori 4,4,65535; bl _s800A0034_0; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s800A0034_0();
extern "C" void f_800A0034() {}
