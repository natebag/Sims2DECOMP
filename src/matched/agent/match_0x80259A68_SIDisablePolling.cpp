// 0x80259A68 SIDisablePolling (108 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-24(1); stw 31,0x14(1); mr. 31,3; bne 0f; lis 3,-32700; addi 3,3,-15972; lwz 3,0x4(3); b 1f; 0:; bl _s80259A68_0; lis 4,-32700; addi 4,4,-15972; lwz 0,0x4(4); rlwinm 31,31,8,24,27; addi 5,4,4; lis 4,-13312; andc 31,0,31; stw 31,0x6430(4); stw 31,0x0(5); bl _s80259A68_1; mr 3,31; 1:; lwz 0,0x1c(1); lwz 31,0x14(1); addi 1,1,24; mtspr 8,0"
extern "C" void _s80259A68_0();
extern "C" void _s80259A68_1();
extern "C" void f_80259A68() {}
