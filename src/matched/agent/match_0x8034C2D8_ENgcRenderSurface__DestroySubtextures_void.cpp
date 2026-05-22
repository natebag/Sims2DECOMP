// 0x8034C2D8 ENgcRenderSurface::DestroySubtextures(void) (60 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); lwz 11,-26392(13); lwz 4,0x28(3); lwz 9,0x0(11); lha 3,0xc0(9); lwz 0,0xc4(9); add 3,11,3; mtspr 8,0; blrl; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void f_8034C2D8() {}
