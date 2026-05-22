// 0x8003FA14 EGlobal::SetCam(ESimsCam (8 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stw 4,0xd0(3)"
extern "C" void f_8003FA14() {}
