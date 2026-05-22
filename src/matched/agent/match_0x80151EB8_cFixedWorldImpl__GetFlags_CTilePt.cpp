// 0x80151EB8 cFixedWorldImpl::GetFlags(CTilePt (80 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); mr 29,4; lwz 28,0x34(3); mr 3,29; bl _s80151EB8_0; mr 30,3; mr 3,29; bl _s80151EB8_1; lwz 9,0xc(28); rlwinm 30,30,2,0,29; lwzx 0,30,9; lbzx 3,3,0; lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"
extern "C" void _s80151EB8_0();
extern "C" void _s80151EB8_1();
extern "C" void f_80151EB8() {}
