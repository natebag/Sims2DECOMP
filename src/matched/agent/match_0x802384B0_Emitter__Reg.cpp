// 0x802384B0 Emitter::Reg(psystem*, bool) (92B)

struct Manager {
    char pad[0x30];
    void* m_notifier;
};

extern Manager* g_soundManager;

void RegisterImpl(int mode, void* handle);
void RegisterNotify(void* notifier, void* player, int flags);

struct Emitter {
    char pad00[0x7C];
    void* m_soundHandle;

    void Reg(int mode, int flag);
};

void Emitter::Reg(int mode, int flag) {
    if (m_soundHandle == 0) return;
    RegisterImpl(mode, m_soundHandle);
    if (flag == 0) return;
    Manager* mgr = g_soundManager;
    RegisterNotify(mgr->m_notifier, this, 0);
}
