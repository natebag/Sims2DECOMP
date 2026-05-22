// 0x802599CC SIEnablePolling (156 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-24(1); stw 31,0x14(1); mr. 31,3; bne 0f; lis 3,-32700; addi 3,3,-15972; lwz 3,0x4(3); b 1f; 0:; bl _s802599CC_0; lis 4,-32700; addi 4,4,-15972; rlwinm 31,31,8,24,31; lwz 0,0x4(4); addi 5,4,4; rlwinm 4,31,28,28,31; andc 0,0,4; stw 0,0x0(5); oris 0,4,1023; ori 0,0,65520; and 31,31,0; lwz 0,0x0(5); rlwinm 31,31,0,24,5; or 0,0,31; stw 0,0x0(5); lis 4,-13312; addi 4,4,25600; lwz 31,0x0(5); lis 0,-32768; stw 0,0x38(4); stw 31,0x30(4); bl _s802599CC_1; mr 3,31; 1:; lwz 0,0x1c(1); lwz 31,0x14(1); addi 1,1,24; mtspr 8,0"
extern "C" void _s802599CC_0();
extern "C" void _s802599CC_1();
extern "C" void f_802599CC() {}
