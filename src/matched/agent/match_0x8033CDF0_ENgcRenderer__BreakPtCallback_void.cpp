// 0x8033CDF0 ENgcRenderer::BreakPtCallback(void) (48 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); li 0,1; li 9,0; stw 0,-26148(13); stw 9,-26152(13); bl _s8033CDF0_0; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s8033CDF0_0();
extern "C" void f_8033CDF0() {}
