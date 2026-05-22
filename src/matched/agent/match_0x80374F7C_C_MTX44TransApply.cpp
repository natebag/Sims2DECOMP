// 0x80374F7C C_MTX44TransApply (152 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="cmplw 3,4; beq 0f; lfs f0,0x0(3); stfs f0,0x0(4); lfs f0,0x4(3); stfs f0,0x4(4); lfs f0,0x8(3); stfs f0,0x8(4); lfs f0,0x10(3); stfs f0,0x10(4); lfs f0,0x14(3); stfs f0,0x14(4); lfs f0,0x18(3); stfs f0,0x18(4); lfs f0,0x20(3); stfs f0,0x20(4); lfs f0,0x24(3); stfs f0,0x24(4); lfs f0,0x28(3); stfs f0,0x28(4); lfs f0,0x30(3); stfs f0,0x30(4); lfs f0,0x34(3); stfs f0,0x34(4); lfs f0,0x38(3); stfs f0,0x38(4); lfs f0,0x3c(3); stfs f0,0x3c(4); 0:; lfs f0,0xc(3); fadds f0,f0,f1; stfs f0,0xc(4); lfs f0,0x1c(3); fadds f0,f0,f2; stfs f0,0x1c(4); lfs f0,0x2c(3); fadds f0,f0,f3; stfs f0,0x2c(4)"
extern "C" void f_80374F7C() {}
