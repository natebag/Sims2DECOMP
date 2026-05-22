// 0x80311C9C EResourceLoaderImpl::UnPauseLoads(void) (44 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); li 0,0; stw 0,0x3e8(3); addi 3,3,1004; bl _s80311C9C_0; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s80311C9C_0();
extern "C" void f_80311C9C() {}
