// 0x8024AFF0 PPCEnableSpeculation (40 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-8(1); bl _s8024AFF0_0; rlwinm 3,3,0,23,21; bl _s8024AFF0_1; lwz 0,0xc(1); addi 1,1,8; mtspr 8,0"
extern "C" void _s8024AFF0_0();
extern "C" void _s8024AFF0_1();
extern "C" void f_8024AFF0() {}
