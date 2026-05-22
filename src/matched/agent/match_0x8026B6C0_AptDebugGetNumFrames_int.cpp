// 0x8026B6C0 AptDebugGetNumFrames(int) (60 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); bl _s8026B6C0_0; mr. 3,3; bne 0f; li 3,0; b 1f; 0:; lwz 9,0x4c(3); lwz 11,0x8(9); lwz 3,0x8(11); 1:; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s8026B6C0_0();
extern "C" void f_8026B6C0() {}
