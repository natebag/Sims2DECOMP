// 0x802939B0 AptCIH::setZombieSate(int) (20 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 0,0x5c(3); rlwinm 4,4,0,30,31; rlwimi 0,4,12,18,19; stw 0,0x5c(3)"
extern "C" void f_802939B0() {}
