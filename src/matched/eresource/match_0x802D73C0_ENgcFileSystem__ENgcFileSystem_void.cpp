// 0x802D73C0 (60B) ENgcFileSystem::ENgcFileSystem(void)
// SI ctor — EFileSystem base + vtable override at +0.

extern char vt_ENgcFileSystem[];

class EFileSystem {
public:
    void* m_vt;
    EFileSystem();
};

class ENgcFileSystem : public EFileSystem {
public:
    ENgcFileSystem();
};

ENgcFileSystem::ENgcFileSystem() {
    m_vt = (void*)vt_ENgcFileSystem;
}
