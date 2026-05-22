// 0x80151C48 cFixedWorldImpl::GetFloor(CTilePt (80 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); mr 29,4; lwz 28,0x2c(3); mr 3,29; bl _s80151C48_0; mr 30,3; mr 3,29; bl _s80151C48_1; lwz 9,0xc(28); rlwinm 30,30,2,0,29; lwzx 0,30,9; lbzx 3,3,0; lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"
extern "C" void _s80151C48_0();
extern "C" void _s80151C48_1();
extern "C" void f_80151C48() {}
