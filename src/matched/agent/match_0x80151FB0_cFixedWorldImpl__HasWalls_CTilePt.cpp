// 0x80151FB0 cFixedWorldImpl::HasWalls(CTilePt (104 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 27,0xc(1); stw 0,0x24(1); mr 29,4; lwz 28,0x38(3); mr 27,5; mr 3,29; bl _s80151FB0_0; mr 30,3; mr 3,29; bl _s80151FB0_1; lwz 11,0xc(28); rlwinm 30,30,2,0,29; rlwinm 3,3,3,0,28; lwzx 9,30,11; lbzx 3,9,3; and 3,3,27; xor 3,3,27; subfic 0,3,0; adde 3,0,3; lwz 0,0x24(1); mtspr 8,0; lmw 27,0xc(1); addi 1,1,32"
extern "C" void _s80151FB0_0();
extern "C" void _s80151FB0_1();
extern "C" void f_80151FB0() {}
