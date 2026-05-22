// 0x80118F0C cSamplePatch::SetLooped(int) (8 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stw 4,0x10(3)"
extern "C" void f_80118F0C() {}
