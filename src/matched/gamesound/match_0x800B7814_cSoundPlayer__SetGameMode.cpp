// 0x800B7814 cSoundPlayer::SetGameMode(snd::eMode) (132B)

extern void* g_cSoundMgr;   // SDA @ -24508
extern void* g_otherMgr;     // SDA @ -26824
extern float g_musicConst[];

struct cSoundPlayer {
    void* m_f0;
    char pad[4];
    int m_f8;
    void SetGameMode(int mode);
};

extern "C" void SoundMgr_PlayMode5(void* mgr, int arg);                         // 0x800b0498
extern "C" void SoundMgr_Play(void* mgr, int id, int mode, int a, int b, float vol);  // 0x800aeb0c

void cSoundPlayer::SetGameMode(int mode) {
    if (m_f8 == 0) return;
    if (m_f0 == 0) return;
    void* mgr = g_cSoundMgr;
    if (mgr == 0) return;
    if (*(int*)((char*)g_otherMgr + 1104) != 0) return;

    if (mode == 5) {
        SoundMgr_PlayMode5((char*)mgr + 48, 5);
    } else {
        SoundMgr_Play(mgr, 36, mode, 0, 0, g_musicConst[0]);
    }
}
