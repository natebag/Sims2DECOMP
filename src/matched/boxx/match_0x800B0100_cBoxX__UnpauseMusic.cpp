// 0x800B0100 cBoxX::UnpauseMusic(void) (92B)

struct cSoundCache {
    void UnpauseGroup(int group);
};

struct cHitMan {
    char _pad[0x50];
    cSoundCache* m_soundCache;
};

extern cHitMan* gHitMan;

struct cSoundModeManager {
    void Unpause();
};

struct cBoxX {
    char _pad1[0x30];
    cSoundModeManager m_sndMgr;
    char _pad2[0x3B];
    int m_sfxPauseCounter;
    int m_musicPauseCounter;
    void UnpauseMusic();
};

void cBoxX::UnpauseMusic() {
    if (m_musicPauseCounter != 0) {
        if (--m_musicPauseCounter != 0)
            return;
    }
    gHitMan->m_soundCache->UnpauseGroup(2);
    m_sndMgr.Unpause();
}
