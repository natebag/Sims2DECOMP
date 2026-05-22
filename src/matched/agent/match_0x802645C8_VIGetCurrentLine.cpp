// 0x802645C8 VIGetCurrentLine (152 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-32(1); stw 31,0x1c(1); stw 30,0x18(1); lwz 31,-23216(13); bl _s802645C8_0; lis 4,-13312; addi 8,4,8192; lhzu 0,0x2c(8); addi 5,4,8192; rlwinm 6,0,0,21,31; 0:; lhz 0,0x0(8); mr 7,6; lhz 4,0x2e(5); rlwinm 6,0,0,21,31; cmplw 7,6; rlwinm 7,4,0,21,31; bne 0b; lwz 4,-23216(13); addi 5,7,-1; addi 6,6,-1; lhz 0,0x1a(4); rlwinm 4,6,1,0,30; divwu 0,5,0; add 30,4,0; bl _s802645C8_1; lhz 0,0x18(31); cmplw 30,0; blt 1f; subf 30,0,30; 1:; rlwinm 3,30,31,1,31; lwz 0,0x24(1); lwz 31,0x1c(1); lwz 30,0x18(1); addi 1,1,32; mtspr 8,0"
extern "C" void _s802645C8_0();
extern "C" void _s802645C8_1();
extern "C" void f_802645C8() {}
