// 0x800AFF60 cBoxX::PauseSFX(void) (96B)

struct cSoundCache {
    void PauseGroup(int group);
};

struct cHitMan {
    char _pad[0x50];
    cSoundCache* m_soundCache;
    void DuckMapRemoveAll();
};

extern cHitMan* gHitMan;

struct cBoxX {
    char _pad[0x6C];
    int m_sfxPauseCounter;
    void PauseSFX();
};

void cBoxX::PauseSFX() {
    m_sfxPauseCounter++;
    gHitMan->m_soundCache->PauseGroup(0);
    gHitMan->m_soundCache->PauseGroup(1);
    gHitMan->m_soundCache->PauseGroup(3);
    gHitMan->DuckMapRemoveAll();
}
