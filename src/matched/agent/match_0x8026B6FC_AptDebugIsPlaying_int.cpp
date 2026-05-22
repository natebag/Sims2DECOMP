// 0x8026B6FC AptDebugIsPlaying(int) (112 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); bl _s8026B6FC_0; mr. 31,3; beq 1f; mr 3,31; li 30,0; bl _s8026B6FC_1; cmpwi 3,18; bne 0f; mr 3,31; bl _s8026B6FC_2; subfic 0,3,0; adde 30,0,3; 0:; cmpwi 30,0; beq 1f; lwz 9,0x4c(31); lwz 3,0x1c(9); rlwinm 3,3,26,31,31; b 2f; 1:; li 3,-1; 2:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s8026B6FC_0();
extern "C" void _s8026B6FC_1();
extern "C" void _s8026B6FC_2();
extern "C" void f_8026B6FC() {}
