// 0x8038C900 GXInitLightAttnA (16 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stfs f1,0x10(3); stfs f2,0x14(3); stfs f3,0x18(3)"
extern "C" void f_8038C900() {}
