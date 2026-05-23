struct EResourceManager {
    void DelRef(void*, int);
};
typedef void (*VFunc)(void*);
struct EResource {
    int* m_vtable;
    EResourceManager* m_pManager;
    char _pad2[0x04];
    volatile short m_numRefs;
    void DelRef();
};
void EResource::DelRef() {
    EResourceManager* mgr = m_pManager;
    if (mgr != 0) {
        mgr->DelRef(this, 1);
    } else {
        m_numRefs = (unsigned short)m_numRefs - 1;
        if (m_numRefs == 0) {
            short adj = *(short*)(m_vtable + 2);
            VFunc fn = (VFunc)m_vtable[3];
            fn((char*)this + adj);
        }
    }
}
