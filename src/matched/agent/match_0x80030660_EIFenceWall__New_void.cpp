// 0x80030660 EIFenceWall::New(void) (40 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); li 3,952; bl _s80030660_0; bl _s80030660_1; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s80030660_0();
extern "C" void _s80030660_1();
extern "C" void f_80030660() {}
