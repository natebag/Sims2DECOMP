// 0x803886B4 GXInitFifoBase (108 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); addi 0,5,-4; stwu 1,-32(1); stw 31,0x1c(1); addi 31,4,0; add 0,31,0; stw 30,0x18(1); addi 30,3,0; addi 4,5,-16384; stw 31,0x0(3); stw 0,0x4(3); li 0,0; stw 5,0x8(3); rlwinm 5,5,31,1,26; stw 0,0x1c(30); bl _s803886B4_0; addi 3,30,0; addi 4,31,0; addi 5,31,0; bl _s803886B4_1; lwz 0,0x24(1); lwz 31,0x1c(1); lwz 30,0x18(1); addi 1,1,32; mtspr 8,0"
extern "C" void _s803886B4_0();
extern "C" void _s803886B4_1();
extern "C" void f_803886B4() {}
