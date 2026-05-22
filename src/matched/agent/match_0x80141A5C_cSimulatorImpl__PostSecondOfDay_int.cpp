// 0x80141A5C cSimulatorImpl::PostSecondOfDay(int) (40 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lha 9,0x1e(3); lha 11,0x14(3); mulli 9,9,60; lha 0,0x20(3); mulli 11,11,3600; add 0,0,9; add 0,0,11; subf 4,0,4; stw 4,0x80(3)"
extern "C" void f_80141A5C() {}
