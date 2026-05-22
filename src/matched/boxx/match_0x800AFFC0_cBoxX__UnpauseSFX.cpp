// 0x800AFFC0 cBoxX::UnpauseSFX(void) (104B)

struct cSoundCache {
    void UnpauseGroup(int group);
};

struct cHitMan {
    char _pad[0x50];
    cSoundCache* m_soundCache;
};

extern cHitMan* gHitMan;

struct cBoxX {
    char _pad[0x6C];
    int m_sfxPauseCounter;
    void UnpauseSFX();
};

void cBoxX::UnpauseSFX() {
    if (m_sfxPauseCounter != 0) {
        if (--m_sfxPauseCounter != 0)
            return;
    }
    gHitMan->m_soundCache->UnpauseGroup(0);
    gHitMan->m_soundCache->UnpauseGroup(1);
    gHitMan->m_soundCache->UnpauseGroup(3);
}
