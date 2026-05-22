// 0x80361660 EStringTableNoCase::InitTable(int) (100 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); mr 30,3; mr 29,4; bl _s80361660_0; rlwinm 28,29,2,0,29; lwz 4,0x8(30); bl _s80361660_1; bl _s80361660_2; li 5,0; mr 4,28; bl _s80361660_3; stw 3,0x8(30); addi 0,29,-1; stw 29,0xc(30); mr 3,30; stw 0,0x10(30); bl _s80361660_4; lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"
extern "C" void _s80361660_0();
extern "C" void _s80361660_1();
extern "C" void _s80361660_2();
extern "C" void _s80361660_3();
extern "C" void _s80361660_4();
extern "C" void f_80361660() {}
