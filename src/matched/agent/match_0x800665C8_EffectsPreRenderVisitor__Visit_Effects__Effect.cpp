// 0x800665C8 EffectsPreRenderVisitor::Visit(Effects::Effect (8 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" replace="b f_800665E4" lines="fmr f31,f11"
extern "C" void f_800665E4();
extern "C" void f_800665C8() {}
