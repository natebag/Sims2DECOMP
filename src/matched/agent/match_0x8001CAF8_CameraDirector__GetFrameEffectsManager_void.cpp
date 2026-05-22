// 0x8001CAF8 CameraDirector::GetFrameEffectsManager(void) (8 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 3,0x2d0(3)"
extern "C" int f_8001CAF8() {}
