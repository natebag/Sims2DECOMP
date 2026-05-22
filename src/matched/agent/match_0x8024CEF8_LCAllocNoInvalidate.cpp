// 0x8024CEF8 LCAllocNoInvalidate (112 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-32(1); stw 31,0x1c(1); stw 30,0x18(1); stw 29,0x14(1); mr 29,3; rlwinm 30,4,27,5,31; bl _s8024CEF8_0; rlwinm 0,3,0,3,3; cmplwi 0,0; bne 0f; bl _s8024CEF8_1; mr 31,3; bl _s8024CEF8_2; mr 3,31; bl _s8024CEF8_3; 0:; mr 4,29; mr 5,30; li 3,0; bl _s8024CEF8_4; lwz 0,0x24(1); lwz 31,0x1c(1); lwz 30,0x18(1); lwz 29,0x14(1); addi 1,1,32; mtspr 8,0"
extern "C" void _s8024CEF8_0();
extern "C" void _s8024CEF8_1();
extern "C" void _s8024CEF8_2();
extern "C" void _s8024CEF8_3();
extern "C" void _s8024CEF8_4();
extern "C" void f_8024CEF8() {}
