// 0x800E3030 cXObjectImpl::GetOverrideRenderPosition(float (20 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lfs f0,0xd0(3); stfs f0,0x0(4); lfs f13,0xd4(3); stfs f13,0x0(5)"
extern "C" void f_800E3030() {}
