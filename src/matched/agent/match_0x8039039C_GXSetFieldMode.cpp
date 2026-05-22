// 0x8039039C GXSetFieldMode (120 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); rlwinm 0,4,0,24,31; stwu 1,-32(1); stw 31,0x1c(1); lis 31,-13311; stw 30,0x18(1); li 30,97; stw 29,0x14(1); mr 29,3; lwz 5,-17720(13); lwz 4,0x7c(5); rlwimi 4,0,22,9,9; stw 4,0x7c(5); stb 30,-32768(31); lwz 0,0x7c(5); stw 0,-32768(31); bl _s8039039C_0; rlwinm 0,29,0,24,31; stb 30,-32768(31); oris 0,0,26624; stw 0,-32768(31); bl _s8039039C_1; lwz 0,0x24(1); lwz 31,0x1c(1); lwz 30,0x18(1); lwz 29,0x14(1); addi 1,1,32; mtspr 8,0"
extern "C" void _s8039039C_0();
extern "C" void _s8039039C_1();
extern "C" void f_8039039C() {}
