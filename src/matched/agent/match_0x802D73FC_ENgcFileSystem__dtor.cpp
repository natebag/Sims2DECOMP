// 0x802D73FC (84B) ENgcFileSystem::~ENgcFileSystem(void)
// Variant L: vtable@+0 + conditional pre-cleanup (when singleton == 0) + parent ~EFileSystem (flag passthrough).

extern char vt_ENgcFileSystem[];
extern void* g_ngcFsSingleton;

void ENgcFileSystem_PreCleanup(void);
void EFileSystem_dtor(void* obj, int flag);

struct ENgcFileSystem {
    void* m_vt_at_0;
    void dtor(int flag);
};

void ENgcFileSystem::dtor(int flag) {
    m_vt_at_0 = vt_ENgcFileSystem;
    if (g_ngcFsSingleton == 0) {
        ENgcFileSystem_PreCleanup();
    }
    EFileSystem_dtor(this, flag);
}
