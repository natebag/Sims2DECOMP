struct Manager {
    char pad[0x30];
    void* m_notifier;
};

extern Manager* g_soundManager;

void SetModeImpl(int mode, void* handle);
void NotifyChange(void* notifier, void* player);

struct cSoundPlayer {
    int m_field00;
    int m_field04;
    char pad08[0x74];
    void* m_soundHandle;

    void SetGameMode(int mode, int notify);
};

void cSoundPlayer::SetGameMode(int mode, int notify) {
    if (m_soundHandle != 0) {
        SetModeImpl(mode, m_soundHandle);
    }
    if (notify != 0) {
        Manager* mgr = g_soundManager;
        int id = m_field04;
        void* notifier = mgr->m_notifier;
        if (id != 0) {
            NotifyChange(notifier, this);
        }
    }
}
