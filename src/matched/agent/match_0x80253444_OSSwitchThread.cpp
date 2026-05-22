// 0x80253444 __OSSwitchThread (92 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-24(1); stw 31,0x14(1); lis 31,-32768; stw 30,0x10(1); addi 30,3,0; mr 4,30; lwz 12,-27896(13); lwz 3,0xe4(31); mtspr 8,12; blrl; stw 30,0xe4(31); mr 3,30; bl _s80253444_0; mr 3,30; bl _s80253444_1; lwz 0,0x1c(1); lwz 31,0x14(1); lwz 30,0x10(1); addi 1,1,24; mtspr 8,0"
extern "C" void _s80253444_0();
extern "C" void _s80253444_1();
extern "C" void f_80253444() {}
