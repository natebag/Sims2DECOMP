// 0x8030C798 TGA_INFO::WriteHeaderToBuffer(void (208 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 28,0x10(1); stw 0,0x24(1); mr 29,3; mr 28,4; addi 30,1,8; lbz 4,0x0(29); stw 28,0x8(1); mr 3,30; bl _s8030C798_0; lbz 4,0x1(29); mr 3,30; bl _s8030C798_1; lbz 4,0x2(29); mr 3,30; bl _s8030C798_2; lhz 4,0x4(29); mr 3,30; bl _s8030C798_3; lhz 4,0x6(29); mr 3,30; bl _s8030C798_4; lbz 4,0x8(29); mr 3,30; bl _s8030C798_5; lhz 4,0xa(29); mr 3,30; bl _s8030C798_6; lhz 4,0xc(29); mr 3,30; bl _s8030C798_7; lhz 4,0xe(29); mr 3,30; bl _s8030C798_8; lhz 4,0x10(29); mr 3,30; bl _s8030C798_9; lbz 4,0x12(29); mr 3,30; bl _s8030C798_10; lbz 4,0x13(29); mr 3,30; bl _s8030C798_11; lwz 3,0x8(1); subf 3,28,3; rlwinm 3,3,0,24,31; lwz 0,0x24(1); mtspr 8,0; lmw 28,0x10(1); addi 1,1,32"
extern "C" void _s8030C798_0();
extern "C" void _s8030C798_1();
extern "C" void _s8030C798_2();
extern "C" void _s8030C798_3();
extern "C" void _s8030C798_4();
extern "C" void _s8030C798_5();
extern "C" void _s8030C798_6();
extern "C" void _s8030C798_7();
extern "C" void _s8030C798_8();
extern "C" void _s8030C798_9();
extern "C" void _s8030C798_10();
extern "C" void _s8030C798_11();
extern "C" void f_8030C798() {}
