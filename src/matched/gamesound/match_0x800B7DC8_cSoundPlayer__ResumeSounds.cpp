// 0x800B7DC8 cSoundPlayer::ResumeSounds(void) (148B)

extern void* g_cSoundMgr;   // SDA @ -24508
extern float g_resumeConst[];

struct cSoundPlayer {
    void* m_f0;
    char pad[4];
    int m_f8;
    int m_fC;
    void ResumeSounds(void);
};

extern "C" void SoundMgr_Play(void* mgr, int id, int a, int b, int c, float vol);
extern "C" void SP_ResumeInternal(cSoundPlayer* self);

void cSoundPlayer::ResumeSounds(void) {
    if (m_f0 != 0 && m_f8 != 0) {
        if (g_cSoundMgr != 0) {
            SoundMgr_Play(g_cSoundMgr, 48, 0, 0, 0, g_resumeConst[0]);
            SoundMgr_Play(g_cSoundMgr, 22, 0, 0, 0, g_resumeConst[0]);
        }
        SP_ResumeInternal(this);
    }
    m_fC = 0;
}
