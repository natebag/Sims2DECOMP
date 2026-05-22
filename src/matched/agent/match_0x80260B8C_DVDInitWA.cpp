// 0x80260B8C __DVDInitWA (64 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; lis 3,-32694; stw 0,0x4(1); li 0,0; li 4,0; stwu 1,-8(1); stw 0,-23292(13); li 0,-1; stw 0,-16952(3); li 3,0; bl _s80260B8C_0; bl _s80260B8C_1; lwz 0,0xc(1); addi 1,1,8; mtspr 8,0"
extern "C" void _s80260B8C_0();
extern "C" void _s80260B8C_1();
extern "C" void f_80260B8C() {}
