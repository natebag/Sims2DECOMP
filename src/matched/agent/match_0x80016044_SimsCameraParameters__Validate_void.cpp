// 0x80016044 SimsCameraParameters::Validate(void) (40 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lfs f13,0x28(3); lfs f0,0x2c(3); fcmpu 0,f0,f13; bge 0f; stfs f13,0x2c(3); 0:; lfs f0,0x38(3); lfs f13,0x28(3); stfs f0,0xb4(3); stfs f13,0xb8(3)"
extern "C" void f_80016044() {}
