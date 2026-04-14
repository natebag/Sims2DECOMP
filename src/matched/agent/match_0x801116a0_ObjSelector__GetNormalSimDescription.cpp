// 0x801116A0 ObjSelector::GetNormalSimDescription (72B)

struct SimDescVtbl {
    char pad[0x158];
    short adj;
    void* func;
};

struct SimDescription {
    char pad[4];
    SimDescVtbl* vtable;
};

struct ObjSelector {
    char pad[0x8c];
    SimDescription* m_altSimDesc;
    char pad2[8];
    SimDescription* m_simDescPtr;
    SimDescription* GetNormalSimDescription() const;
};

SimDescription* ObjSelector::GetNormalSimDescription() const {
    if (m_simDescPtr != 0) {
        SimDescVtbl* vt = m_simDescPtr->vtable;
        short adj = vt->adj;
        void* fn = vt->func;
        typedef SimDescription* (*SimDescFunc)(void*);
        SimDescFunc f = (SimDescFunc)fn;
        return f((char*)m_simDescPtr + adj);
    }
    return m_altSimDesc;
}
