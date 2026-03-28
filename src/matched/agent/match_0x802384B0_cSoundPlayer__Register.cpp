struct Manager {
    char pad[0x30];
    void* m_notifier;
};

extern Manager* g_soundManager;

void RegisterImpl(int mode, void* handle);
void RegisterNotify(void* notifier, void* player, int flags);

struct cSoundPlayer {
    char pad00[0x7C];
    void* m_soundHandle;

    void Register(int mode, int flag);
};

void cSoundPlayer::Register(int mode, int flag) {
    if (m_soundHandle != 0) {
        RegisterImpl(mode, m_soundHandle);
    }
    if (flag != 0) {
        Manager* mgr = g_soundManager;
        RegisterNotify(mgr->m_notifier, this, 0);
    }
}
