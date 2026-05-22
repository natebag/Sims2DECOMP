// 0x80255304 __OSSetTime (132 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-40(1); stw 31,0x24(1); stw 30,0x20(1); stw 29,0x1c(1); mr 30,3; mr 29,4; bl _s80255304_0; mr 31,3; bl _s80255304_1; lis 5,-32768; subfc 6,29,4; lwz 0,0x30dc(5); subfe 4,30,3; lwz 3,0x30d8(5); addc 0,0,6; stw 0,0x30dc(5); adde 0,3,4; mr 4,29; stw 0,0x30d8(5); mr 3,30; bl _s80255304_2; bl _s80255304_3; mr 3,31; bl _s80255304_4; lwz 0,0x2c(1); lwz 31,0x24(1); lwz 30,0x20(1); lwz 29,0x1c(1); addi 1,1,40; mtspr 8,0"
extern "C" void _s80255304_0();
extern "C" void _s80255304_1();
extern "C" void _s80255304_2();
extern "C" void _s80255304_3();
extern "C" void _s80255304_4();
extern "C" void f_80255304() {}
