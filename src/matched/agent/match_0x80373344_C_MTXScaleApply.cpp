// 0x80373344 C_MTXScaleApply (148 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lfs f0,0x0(3); fmuls f0,f0,f1; stfs f0,0x0(4); lfs f0,0x4(3); fmuls f0,f0,f1; stfs f0,0x4(4); lfs f0,0x8(3); fmuls f0,f0,f1; stfs f0,0x8(4); lfs f0,0xc(3); fmuls f0,f0,f1; stfs f0,0xc(4); lfs f0,0x10(3); fmuls f0,f0,f2; stfs f0,0x10(4); lfs f0,0x14(3); fmuls f0,f0,f2; stfs f0,0x14(4); lfs f0,0x18(3); fmuls f0,f0,f2; stfs f0,0x18(4); lfs f0,0x1c(3); fmuls f0,f0,f2; stfs f0,0x1c(4); lfs f0,0x20(3); fmuls f0,f0,f3; stfs f0,0x20(4); lfs f0,0x24(3); fmuls f0,f0,f3; stfs f0,0x24(4); lfs f0,0x28(3); fmuls f0,f0,f3; stfs f0,0x28(4); lfs f0,0x2c(3); fmuls f0,f0,f3; stfs f0,0x2c(4)"
extern "C" void f_80373344() {}
