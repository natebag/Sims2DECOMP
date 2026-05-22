// 0x80255388 __OSGetSystemTime (100 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-32(1); stw 31,0x1c(1); stw 30,0x18(1); stw 29,0x14(1); bl _s80255388_0; mr 31,3; bl _s80255388_1; lis 6,-32768; lwz 5,0x30dc(6); lwz 0,0x30d8(6); addc 29,5,4; adde 30,0,3; mr 3,31; bl _s80255388_2; mr 4,29; mr 3,30; lwz 0,0x24(1); lwz 31,0x1c(1); lwz 30,0x18(1); lwz 29,0x14(1); addi 1,1,32; mtspr 8,0"
extern "C" void _s80255388_0();
extern "C" void _s80255388_1();
extern "C" void _s80255388_2();
extern "C" void f_80255388() {}
