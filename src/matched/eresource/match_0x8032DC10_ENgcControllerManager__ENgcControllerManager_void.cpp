// 0x8032DC10 (64B) ENgcControllerManager::ENgcControllerManager(void)
// SI ctor — EControllerManager base + vtable at +0x20 + SDA singleton register.

extern char vt_ENgcControllerManager[];
extern class ENgcControllerManager* g_pENgcControllerManager;

class EControllerManager {
public:
    void* m_base_vt;
    EControllerManager();
};

class ENgcControllerManager : public EControllerManager {
public:
    char pad[0x20 - 4];
    void* m_vt_at_20;
    ENgcControllerManager();
};

ENgcControllerManager::ENgcControllerManager() {
    m_vt_at_20 = (void*)vt_ENgcControllerManager;
    g_pENgcControllerManager = this;
}
