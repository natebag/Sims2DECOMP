// 0x8038CBE4 GXInitLightDir (28 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="fneg f4,f1; fneg f1,f2; fneg f0,f3; stfs f4,0x34(3); stfs f1,0x38(3); stfs f0,0x3c(3)"
extern "C" void f_8038CBE4() {}
