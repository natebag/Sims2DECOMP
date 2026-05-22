// 0x80377D20 AXInitEx (76 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-24(1); stw 31,0x14(1); mr 31,3; lwz 3,-25368(13); bl _s80377D20_0; bl _s80377D20_1; bl _s80377D20_2; bl _s80377D20_3; bl _s80377D20_4; bl _s80377D20_5; mr 3,31; bl _s80377D20_6; lwz 0,0x1c(1); lwz 31,0x14(1); addi 1,1,24; mtspr 8,0"
extern "C" void _s80377D20_0();
extern "C" void _s80377D20_1();
extern "C" void _s80377D20_2();
extern "C" void _s80377D20_3();
extern "C" void _s80377D20_4();
extern "C" void _s80377D20_5();
extern "C" void _s80377D20_6();
extern "C" void f_80377D20() {}
