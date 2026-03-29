struct EResourceManager {
    void AddRef(void*);
};
struct EResource {
    char _pad[0x04];
    EResourceManager* m_pManager;
    char _pad2[0x04];
    short m_numRefs;
    void AddRef();
};
void EResource::AddRef() {
    EResourceManager* mgr = m_pManager;
    if (mgr != 0) {
        mgr->AddRef(this);
    } else {
        m_numRefs = m_numRefs + 1;
    }
}
