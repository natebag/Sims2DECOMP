// 0x8023850C Emitter::UnReg(psystem*, bool) (100B)

struct Manager {
    char pad[0x30];
    void* m_notifier;
};

extern Manager* g_soundManager;

void PEmitterUnReg(int mode, void* handle);
void NotifyChange(void* notifier, void* player);

struct Emitter {
    int m_field00;
    int m_field04;
    char pad08[0x74];
    void* m_soundHandle;

    void UnReg(int mode, int notify);
};

void Emitter::UnReg(int mode, int notify) {
    if (m_soundHandle == 0) return;
    PEmitterUnReg(mode, m_soundHandle);
    if (notify == 0) return;
    Manager* mgr = g_soundManager;
    int id = m_field04;
    void* notifier = mgr->m_notifier;
    if (id == 0) return;
    NotifyChange(notifier, this);
}
