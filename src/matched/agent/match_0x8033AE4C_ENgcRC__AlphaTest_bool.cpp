// 0x8033AE4C ENgcRC::AlphaTest(bool, (124 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stw 0,0x1c(1); lis 9,-32702; lis 11,-32702; lfs f13,0x1b88(9); lfs f0,0x1b8c(11); fmuls f1,f1,f13; fcmpu 0,f1,f0; blt 0f; fmr f0,f1; fcmpu 0,f1,f13; ble 0f; fmr f0,f13; 0:; fctiwz f13,f0; li 0,44; stfd f13,0x10(1); lis 3,-32691; stb 4,0x9(1); addi 3,3,21688; lwz 9,0x14(1); addi 4,1,8; stb 0,0x8(1); stb 5,0xa(1); stb 9,0xb(1); stw 6,0xc(1); bl _s8033AE4C_0; lwz 0,0x1c(1); mtspr 8,0; addi 1,1,24"
extern "C" void _s8033AE4C_0();
extern "C" void f_8033AE4C() {}
