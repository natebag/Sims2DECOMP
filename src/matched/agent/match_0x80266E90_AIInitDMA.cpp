// 0x80266E90 AIInitDMA (136 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-24(1); stw 31,0x14(1); addi 31,4,0; stw 30,0x10(1); addi 30,3,0; bl _s80266E90_0; lis 4,-13312; lhz 0,0x5030(4); addi 5,4,20480; addi 6,4,20480; addi 7,4,20480; rlwinm 4,0,0,0,21; rlwinm 0,30,16,16,31; or 0,4,0; sth 0,0x30(5); rlwinm 0,30,0,16,31; lhz 4,0x32(6); rlwinm 4,4,0,27,15; or 0,4,0; sth 0,0x32(6); rlwinm 0,31,27,16,31; lhz 4,0x36(7); rlwinm 4,4,0,0,16; or 0,4,0; sth 0,0x36(7); bl _s80266E90_1; lwz 0,0x1c(1); lwz 31,0x14(1); lwz 30,0x10(1); addi 1,1,24; mtspr 8,0"
extern "C" void _s80266E90_0();
extern "C" void _s80266E90_1();
extern "C" void f_80266E90() {}
