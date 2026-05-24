// 0x800665C8 EffectsPreRenderVisitor::Visit(Effects::Effect (8 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" replace="b f_800665E4" lines="fmr f31,f11"

struct Effects {
    void Visit_Effects__Effect();
};

void Effects::Visit_Effects__Effect() {
}
