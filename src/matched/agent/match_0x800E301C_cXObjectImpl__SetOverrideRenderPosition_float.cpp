// 0x800E301C cXObjectImpl::SetOverrideRenderPosition(float, (20 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="li 0,1; stfs f1,0xd0(3); stw 0,0xcc(3); stfs f2,0xd4(3)"
extern "C" void f_800E301C() {}
