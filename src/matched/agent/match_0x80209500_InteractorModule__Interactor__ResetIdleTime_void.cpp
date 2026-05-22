// 0x80209500 InteractorModule::Interactor::ResetIdleTime(void) (16 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lis 9,-32704; lfs f0,-12704(9); stfs f0,0x58(3)"
extern "C" void f_80209500() {}
