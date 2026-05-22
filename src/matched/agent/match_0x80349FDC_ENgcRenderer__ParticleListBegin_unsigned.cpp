// 0x80349FDC ENgcRenderer::ParticleListBegin(unsigned (80 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); mr 30,3; mr 29,4; mr 28,5; bl _s80349FDC_0; rlwinm 4,29,6,0,25; li 5,0; bl _s80349FDC_1; mr 0,3; stw 28,0x4664(30); stw 29,0x4660(30); stw 0,0x465c(30); lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"
extern "C" void _s80349FDC_0();
extern "C" void _s80349FDC_1();
extern "C" void f_80349FDC() {}
