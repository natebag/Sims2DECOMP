// 0x8038CD38 GXInitLightColor (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 0,0x0(4); stw 0,0xc(3)"
extern "C" void f_8038CD38() {}
