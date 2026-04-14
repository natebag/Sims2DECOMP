// 0x800B7D34 cSoundPlayer::PauseSounds(void) (148B)

extern void* g_cSoundMgr;   // SDA @ -24508
extern float g_pauseConst[];

struct cSoundPlayer {
    void* m_f0;
    char pad[4];
    int m_f8;
    int m_fC;
    void PauseSounds(void);
};

extern "C" void SoundMgr_Play(void* mgr, int id, int a, int b, int c, float vol);  // 0x800aeb0c
extern "C" void SP_PauseInternal(cSoundPlayer* self);                                // 0x800b7e5c

void cSoundPlayer::PauseSounds(void) {
    m_fC = 1;
    if (m_f0 == 0) return;
    if (m_f8 == 0) return;
    if (g_cSoundMgr != 0) {
        SoundMgr_Play(g_cSoundMgr, 47, 0, 0, 0, g_pauseConst[0]);
        SoundMgr_Play(g_cSoundMgr, 21, 0, 0, 0, g_pauseConst[0]);
    }
    SP_PauseInternal(this);
}
