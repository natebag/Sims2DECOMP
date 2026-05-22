// 0x8001EA74 ESimsCam::GetZoom(void) (8 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lfs f1,0x448(3)"
extern "C" int f_8001EA74() {}
