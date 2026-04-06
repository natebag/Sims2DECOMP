// 0x8005A2E0 PlumbBob::SetModel (52b)

extern int SetModelTarget(void*);

struct PlumbBob {
    char pad[0x164];
    void* m_model;
};

int PlumbBob_SetModel(PlumbBob* self, unsigned int param) {
    void* p = self->m_model;
    if (!p) return 0;
    return SetModelTarget(p);
}
