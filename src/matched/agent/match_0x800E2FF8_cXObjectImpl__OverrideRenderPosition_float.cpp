// 0x800E2FF8 cXObjectImpl::OverrideRenderPosition(float (36 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 0,0xcc(3); cmpwi 0,0; beq 0f; lfs f0,0xd0(3); stfs f0,0x0(4); lfs f13,0xd4(3); stfs f13,0x0(5); 0:; lwz 3,0xcc(3)"
extern "C" void f_800E2FF8() {}
