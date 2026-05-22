// 0x80090088 ELiveMode::SetGoingToNeighborhoodMode(bool) (8 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stw 4,0x24(3)"
extern "C" void f_80090088() {}
