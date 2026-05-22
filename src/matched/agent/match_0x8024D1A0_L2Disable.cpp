// 0x8024D1A0 L2Disable (48 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-8(1); sync; bl _s8024D1A0_0; rlwinm 3,3,0,1,31; bl _s8024D1A0_1; sync; lwz 0,0xc(1); addi 1,1,8; mtspr 8,0"
extern "C" void _s8024D1A0_0();
extern "C" void _s8024D1A0_1();
extern "C" void f_8024D1A0() {}
