// 0x8018CC40 LoadGameTarget::BGCall_PerformLoad() (76B)

class LoadGameTarget {
public:
    void BGCall_PerformLoad();
    static void BGExec_PerformLoad(void* p);
};

extern void* g_BGCallMgr_SDA;
extern int g_BGCallFlag_SDA;

void LoadGameTarget::BGCall_PerformLoad() {
    void* mgr = g_BGCallMgr_SDA;
    char* vt = *(char**)mgr;
    short adj = *(short*)(vt + 0x48);
    void* fn = *(void**)(vt + 0x4C);
    g_BGCallFlag_SDA = 0;
    ((void(*)(void*, void(*)(void*), LoadGameTarget*))fn)((char*)mgr + adj, &LoadGameTarget::BGExec_PerformLoad, this);
}
