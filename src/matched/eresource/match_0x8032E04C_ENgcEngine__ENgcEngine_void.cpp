// 0x8032E04C (80B) ENgcEngine::ENgcEngine(void)
// SI ctor — EEngine base + vtable @ 0 + SDA singleton + DVDSetAutoFatalMessaging(1) + zero @ +0x50.

extern char vt_ENgcEngine[];
extern class ENgcEngine* g_pENgcEngine;
extern "C" int DVDSetAutoFatalMessaging(int);

class EEngine {
public:
    void* m_base_vt;
    EEngine();
};

class ENgcEngine : public EEngine {
public:
    char pad04_4F[0x50 - 4];
    int m_field50;
    ENgcEngine();
};

ENgcEngine::ENgcEngine() {
    m_base_vt = (void*)vt_ENgcEngine;
    g_pENgcEngine = this;
    DVDSetAutoFatalMessaging(1);
    m_field50 = 0;
}
