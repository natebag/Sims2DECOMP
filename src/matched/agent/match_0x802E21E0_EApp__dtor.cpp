// 0x802E21E0 (52B) EApp::~EApp(void)
// Variant L: non-deleting dtor (singleton) — vtable@+0x338 + clear SDA singleton + parent ~EThread.

extern char vt_EApp[];
extern void* g_appSingleton;

void EThread_dtor(void* obj);

struct EApp {
    char pad_0_337[824];
    void* m_vt_at_338;
    void dtor();
};

void EApp::dtor() {
    m_vt_at_338 = vt_EApp;
    g_appSingleton = 0;
    EThread_dtor(this);
}
