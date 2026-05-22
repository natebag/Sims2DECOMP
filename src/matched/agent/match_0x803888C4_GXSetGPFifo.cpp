// 0x803888C4 GXSetGPFifo (376 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-24(1); stw 31,0x14(1); stw 30,0x10(1); mr 30,3; bl _s803888C4_0; mr 31,3; bl _s803888C4_1; li 3,0; li 4,0; bl _s803888C4_2; stw 30,-21956(13); lwz 3,-21996(13); lwz 0,0x0(30); sth 0,0x20(3); lwz 0,0x4(30); lwz 3,-21996(13); sth 0,0x24(3); lwz 0,0x1c(30); lwz 3,-21996(13); sth 0,0x30(3); lwz 0,0x18(30); lwz 3,-21996(13); sth 0,0x34(3); lwz 0,0x14(30); lwz 3,-21996(13); sth 0,0x38(3); lwz 0,0xc(30); lwz 3,-21996(13); sth 0,0x28(3); lwz 0,0x10(30); lwz 3,-21996(13); sth 0,0x2c(3); lwz 0,0x0(30); lwz 3,-21996(13); rlwinm 0,0,16,18,31; sth 0,0x22(3); lwz 0,0x4(30); lwz 3,-21996(13); rlwinm 0,0,16,18,31; sth 0,0x26(3); lwz 0,0x1c(30); lwz 3,-21996(13); srawi 0,0,16; sth 0,0x32(3); lwz 0,0x18(30); lwz 3,-21996(13); rlwinm 0,0,16,18,31; sth 0,0x36(3); lwz 0,0x14(30); lwz 3,-21996(13); rlwinm 0,0,16,18,31; sth 0,0x3a(3); lwz 0,0xc(30); lwz 3,-21996(13); rlwinm 0,0,16,16,31; sth 0,0x2a(3); lwz 0,0x10(30); lwz 3,-21996(13); rlwinm 0,0,16,16,31; sth 0,0x2e(3); bl _s803888C4_3; lwz 3,-21960(13); lwz 0,-21956(13); cmplw 3,0; bne 0f; li 0,1; stb 0,-21948(13); li 3,1; li 4,0; bl _s803888C4_4; li 3,1; bl _s803888C4_5; b 1f; 0:; li 0,0; stb 0,-21948(13); li 3,0; li 4,0; bl _s803888C4_6; li 3,0; bl _s803888C4_7; 1:; li 3,1; li 4,1; bl _s803888C4_8; bl _s803888C4_9; mr 3,31; bl _s803888C4_10; lwz 0,0x1c(1); lwz 31,0x14(1); lwz 30,0x10(1); addi 1,1,24; mtspr 8,0"
extern "C" void _s803888C4_0();
extern "C" void _s803888C4_1();
extern "C" void _s803888C4_2();
extern "C" void _s803888C4_3();
extern "C" void _s803888C4_4();
extern "C" void _s803888C4_5();
extern "C" void _s803888C4_6();
extern "C" void _s803888C4_7();
extern "C" void _s803888C4_8();
extern "C" void _s803888C4_9();
extern "C" void _s803888C4_10();
extern "C" void f_803888C4() {}
