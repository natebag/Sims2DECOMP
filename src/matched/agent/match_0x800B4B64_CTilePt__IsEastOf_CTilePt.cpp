// 0x800B4B64 CTilePt::IsEastOf(CTilePt (68 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 29,4; bl _s800B4B64_0; mr 30,3; mr 3,29; bl _s800B4B64_1; cmpw cr7,30,3; mfcr 3; rlwinm 3,3,30,31,31; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s800B4B64_0();
extern "C" void _s800B4B64_1();
extern "C" void f_800B4B64() {}
