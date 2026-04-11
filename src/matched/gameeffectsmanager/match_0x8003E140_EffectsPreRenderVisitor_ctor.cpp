// 0x8003E140 EffectsPreRenderVisitor::EffectsPreRenderVisitor (20b)

extern int EffectsPreRenderVisitor_vtable[];

struct EffectsPreRenderVisitor {
    int* m_vt;
    EffectsPreRenderVisitor();
};

EffectsPreRenderVisitor::EffectsPreRenderVisitor() {
    *(int**)this = EffectsPreRenderVisitor_vtable;
}
