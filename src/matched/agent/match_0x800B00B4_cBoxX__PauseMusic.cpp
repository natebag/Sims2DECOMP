// 0x800B00B4 cBoxX::PauseMusic (76B)

class cSoundModeManager {
public:
    void Pause();
};

class cSoundCache {
public:
    static void PauseGroup(int group, int p2);
};

struct AudioGroupInfo {
    char pad[0x50];
    int m_groupId;
};

extern AudioGroupInfo* g_audio_SDA;

class cBoxX {
public:
    char pad[0x30];
    char m_sndMgr[0x40];
    int m_70;
    void PauseMusic();
};

void cBoxX::PauseMusic() {
    ++m_70;
    cSoundCache::PauseGroup(g_audio_SDA->m_groupId, 2);
    ((cSoundModeManager*)&m_sndMgr)->Pause();
}
