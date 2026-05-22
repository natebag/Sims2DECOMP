// 0x803C418C EFolder::GetBlockOffset(int) (20 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 0,0x0(3); rlwinm 4,4,2,0,29; add 4,4,0; lwz 3,0x4(4)"
extern "C" int f_803C418C() {}
