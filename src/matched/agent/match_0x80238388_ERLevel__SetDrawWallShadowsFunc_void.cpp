// 0x80238388 ERLevel::SetDrawWallShadowsFunc(void (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="addis 3,3,3; stw 4,-7464(3)"
extern "C" void f_80238388() {}
