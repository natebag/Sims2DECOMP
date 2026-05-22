// 0x80151E60 cFixedWorldImpl::SetRoom(CTilePt (88 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 27,0xc(1); stw 0,0x24(1); mr 29,4; lwz 28,0x30(3); mr 27,5; mr 3,29; bl _s80151E60_0; mr 30,3; mr 3,29; bl _s80151E60_1; lwz 11,0xc(28); rlwinm 30,30,2,0,29; rlwinm 3,3,1,0,30; lwzx 9,30,11; sthx 27,9,3; lwz 0,0x24(1); mtspr 8,0; lmw 27,0xc(1); addi 1,1,32"
extern "C" void _s80151E60_0();
extern "C" void _s80151E60_1();
extern "C" void f_80151E60() {}
