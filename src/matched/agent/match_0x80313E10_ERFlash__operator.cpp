// 0x80313E10 ERFlash::operator (44 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); mr 4,3; lis 3,-32693; addi 3,3,31260; bl _s80313E10_0; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s80313E10_0();
extern "C" void f_80313E10() {}
