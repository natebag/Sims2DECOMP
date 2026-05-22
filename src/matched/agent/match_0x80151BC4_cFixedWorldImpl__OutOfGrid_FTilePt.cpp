// 0x80151BC4 cFixedWorldImpl::OutOfGrid(FTilePt (108 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 29,0x14(1); stw 0,0x24(1); mr 29,3; li 5,1; lwz 30,0x0(29); addi 3,1,8; lha 0,0x60(30); addi 30,30,96; add 29,29,0; bl _s80151BC4_0; lwz 0,0x4(30); addi 4,1,8; mr 3,29; mtspr 8,0; blrl; mr 30,3; li 4,2; addi 3,1,8; bl _s80151BC4_1; mr 3,30; lwz 0,0x24(1); mtspr 8,0; lmw 29,0x14(1); addi 1,1,32"
extern "C" void _s80151BC4_0();
extern "C" void _s80151BC4_1();
extern "C" void f_80151BC4() {}
