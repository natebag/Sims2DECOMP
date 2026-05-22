// 0x8038846C GXOverflowHandler (80 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; li 3,0; stw 0,0x4(1); li 4,1; stwu 1,-8(1); lwz 5,-21936(13); addi 0,5,1; stw 0,-21936(13); bl _s8038846C_0; li 3,1; li 4,0; bl _s8038846C_1; li 0,1; lwz 3,-21952(13); stw 0,-21944(13); bl _s8038846C_2; lwz 0,0xc(1); addi 1,1,8; mtspr 8,0"
extern "C" void _s8038846C_0();
extern "C" void _s8038846C_1();
extern "C" void _s8038846C_2();
extern "C" void f_8038846C() {}
