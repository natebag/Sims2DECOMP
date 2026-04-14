// 0x800B7F54 cSoundPlayer::SetOldFXVolume(int) (136B)

extern void* g_cSoundMgr;   // SDA @ -24508
extern float g_fxVolConst[];

struct cSoundConfig {
    char pad[28];
    unsigned char m_oldFXVol;
};

extern cSoundConfig* g_soundConfig[4];  // absolute via lis

struct cSoundPlayer {
    void* m_f0;
    char pad[4];
    int m_f8;
    void SetOldFXVolume(int vol);
};

extern "C" void SoundMgr_Play(void* mgr, int id, int mode, int a, int b, float vol);  // 0x800aeb0c

void cSoundPlayer::SetOldFXVolume(int vol) {
    g_soundConfig[0]->m_oldFXVol = (unsigned char)vol;
    if (m_f0 == 0) return;
    if (m_f8 == 0) return;
    SoundMgr_Play(g_cSoundMgr, 37, vol, 0, 0, g_fxVolConst[0]);
    SoundMgr_Play(g_cSoundMgr, 39, vol, 0, 0, g_fxVolConst[0]);
}
