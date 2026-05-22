// 0x8003FA24 EGlobal::SetCameraDirector(CameraDirector (8 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stw 4,0xe0(3)"
extern "C" void f_8003FA24() {}
