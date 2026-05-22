// 0x800DB9A0 cXObject::SetGlobalFreeWillOverride(bool) (8 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stw 3,-31908(13)"
extern "C" void f_800DB9A0() {}
