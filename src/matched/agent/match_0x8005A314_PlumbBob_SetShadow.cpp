// 0x8005A314 PlumbBob::SetShadow (52b)

extern int SetShadowTarget(void*);

struct PlumbBob {
    char pad[0x164];
    void* m_shadow;
};

int PlumbBob_SetShadow(PlumbBob* self, unsigned int param) {
    void* p = self->m_shadow;
    if (!p) return 0;
    return SetShadowTarget(p);
}
