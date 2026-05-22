// 0x8022813C EILight::GetIntensityScale(void) (36 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lfs f13,0x9c(4); mr 9,3; addi 4,4,156; stfs f13,0x0(9); lfs f0,0x4(4); stfs f0,0x4(9); lfs f13,0x8(4); stfs f13,0x8(9)"
extern "C" void f_8022813C() {}
