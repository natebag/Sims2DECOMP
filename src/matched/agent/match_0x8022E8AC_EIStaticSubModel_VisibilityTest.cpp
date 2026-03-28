struct EIStaticSubModel_VT {
    char pad[0x3C];
    char m_bound;
};

extern int BoundSphere_VisibilityTest2(void* window, void* bound);

int EIStaticSubModel_VisibilityTest(EIStaticSubModel_VT* self, void* window) {
    return BoundSphere_VisibilityTest2(window, &self->m_bound);
}
