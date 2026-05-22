// 0x802382E0 ERLevel::SetRainBlend(float) (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="addis 3,3,3; stfs f1,-7448(3)"
extern "C" void f_802382E0() {}
