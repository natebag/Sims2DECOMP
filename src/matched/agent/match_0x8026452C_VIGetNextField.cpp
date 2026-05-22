// 0x8026452C VIGetNextField (156 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-40(1); stw 31,0x24(1); stw 30,0x20(1); bl _s8026452C_0; addi 30,3,0; addi 3,1,16; addi 4,1,20; bl _s8026452C_1; lwz 5,-23216(13); lwz 3,0x10(1); lhz 0,0x1a(5); addi 3,3,-1; lwz 4,0x14(1); divwu 3,3,0; lhz 0,0x18(5); addi 4,4,-1; rlwinm 4,4,1,0,30; add 3,4,3; cmplw 3,0; bge 0f; li 31,1; b 1f; 0:; li 31,0; 1:; mr 3,30; bl _s8026452C_2; lis 3,-32694; addi 3,3,-16504; lhz 0,0xa(3); xori 3,31,1; rlwinm 0,0,0,31,31; xor 3,3,0; lwz 0,0x2c(1); lwz 31,0x24(1); lwz 30,0x20(1); addi 1,1,40; mtspr 8,0"
extern "C" void _s8026452C_0();
extern "C" void _s8026452C_1();
extern "C" void _s8026452C_2();
extern "C" void f_8026452C() {}
