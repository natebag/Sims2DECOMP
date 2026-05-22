// 0x802094F0 InteractorModule::Interactor::AddIdleTime(float) (16 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lfs f0,0x58(3); fadds f0,f0,f1; stfs f0,0x58(3)"
extern "C" void f_802094F0() {}
