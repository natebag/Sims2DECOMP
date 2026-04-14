// 0x800B7440 cSoundPlayer::Shutdown(void) (132B)

extern void* g_cSoundMgr;  // SDA @ -24508

struct SoundMgr {
    char pad[120];
    int* m_vt;  // offset 120
};

struct cSoundPlayer {
    void* m_f0;
    char pad[4];
    int m_f8;

    void Shutdown(void);
};

extern "C" void SndUnreg(SoundMgr* p);  // 0x800ad89c

void cSoundPlayer::Shutdown(void) {
    if (m_f8 == 0) return;
    if (m_f0 == 0) return;
    SoundMgr* mgr = (SoundMgr*)g_cSoundMgr;
    m_f0 = 0;
    if (mgr == 0) return;
    SndUnreg(mgr);
    SoundMgr* mgr2 = (SoundMgr*)g_cSoundMgr;
    if (mgr2 != 0) {
        int* vt = mgr2->m_vt;
        short adj = *(short*)((char*)vt + 8);
        void (*fn)(void*, int) = (void (*)(void*, int))*(void**)((char*)vt + 12);
        fn((char*)mgr2 + adj, 3);
    }
    g_cSoundMgr = 0;
}
