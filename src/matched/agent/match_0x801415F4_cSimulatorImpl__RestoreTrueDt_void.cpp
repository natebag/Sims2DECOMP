// 0x801415F4 cSimulatorImpl::RestoreTrueDt(void) (24 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lfs f0,0xa4(3); lis 9,-32706; lfs f13,-10644(9); stfs f0,-26800(13); stfs f13,0xa4(3)"
extern "C" void f_801415F4() {}
