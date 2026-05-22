// 0x80206120 InteractorModule::DirectInteractor::ExitDirectControl(void) (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="li 0,1; stw 0,0x6c(3)"
extern "C" void f_80206120() {}
