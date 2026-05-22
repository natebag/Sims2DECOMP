// 0x80238244 ERLevel::SetSunYawOffset(float) (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="addis 3,3,3; stfs f1,-7076(3)"
extern "C" void f_80238244() {}
