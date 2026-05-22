// 0x8033CAB8 ENgcRenderer::CycleToNextFrameBuffer(void) (100 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 30,3; lwz 3,0x34c(30); bl _s8033CAB8_0; lwz 9,0x340(30); addi 11,30,836; addi 9,9,1; rlwinm 0,9,1,31,31; add 0,9,0; rlwinm 0,0,0,0,30; subf 9,0,9; stw 9,0x340(30); rlwinm 9,9,2,0,29; lwzx 0,11,9; stw 0,0x34c(30); bl _s8033CAB8_1; bl _s8033CAB8_2; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s8033CAB8_0();
extern "C" void _s8033CAB8_1();
extern "C" void _s8033CAB8_2();
extern "C" void f_8033CAB8() {}
