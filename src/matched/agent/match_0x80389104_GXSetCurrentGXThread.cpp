// 0x80389104 GXSetCurrentGXThread (76 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-16(1); stw 31,0xc(1); stw 30,0x8(1); bl _s80389104_0; lwz 30,-21952(13); mr 31,3; bl _s80389104_1; stw 3,-21952(13); mr 3,31; bl _s80389104_2; mr 3,30; lwz 0,0x14(1); lwz 31,0xc(1); lwz 30,0x8(1); addi 1,1,16; mtspr 8,0"
extern "C" void _s80389104_0();
extern "C" void _s80389104_1();
extern "C" void _s80389104_2();
extern "C" void f_80389104() {}
