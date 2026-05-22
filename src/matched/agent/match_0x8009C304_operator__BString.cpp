// 0x8009C304 operator<(BString (44 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); li 5,0; li 6,-1; bl _s8009C304_0; rlwinm 3,3,1,31,31; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s8009C304_0();
extern "C" void f_8009C304() {}
