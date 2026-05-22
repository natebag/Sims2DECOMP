// 0x8024D174 L2Enable (44 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-8(1); bl _s8024D174_0; oris 0,3,32768; rlwinm 3,0,0,11,9; bl _s8024D174_1; lwz 0,0xc(1); addi 1,1,8; mtspr 8,0"
extern "C" void _s8024D174_0();
extern "C" void _s8024D174_1();
extern "C" void f_8024D174() {}
