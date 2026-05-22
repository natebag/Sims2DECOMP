// 0x8038CD0C GXInitSpecularDirHA (44 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stfs f4,0x34(3); stfs f5,0x38(3); stfs f6,0x3c(3); lfs f0,-17568(13); fmuls f4,f0,f1; fmuls f1,f0,f2; fmuls f0,f0,f3; stfs f4,0x28(3); stfs f1,0x2c(3); stfs f0,0x30(3)"
extern "C" void f_8038CD0C() {}
