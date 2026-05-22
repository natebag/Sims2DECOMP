// 0x802671EC AIGetDSPSampleRate (20 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lis 3,-13312; lwz 0,0x6c00(3); rlwinm 0,0,26,31,31; xori 3,0,1"
extern "C" int f_802671EC() {}
