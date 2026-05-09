// 0x8022C834 EIStaticModel::VisibilityTest(E3DWindow &) (44B)
// PRAGMA_STUB: EIStaticModel::VisibilityTest(E3DWindow &)
struct EIStaticModel_VT {
    char pad[0x3C];
    char m_bound;
};

extern int BoundSphere_VisibilityTest(void* window, void* bound);

int EIStaticModel_VisibilityTest(EIStaticModel_VT* self, void* window) {
    return BoundSphere_VisibilityTest(window, &self->m_bound);
}
