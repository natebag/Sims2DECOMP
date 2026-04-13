// 0x800B0478 cSoundModeManager::FadeOutSFX (12b)
// FLAGS: -fno-schedule-insns

class cSoundModeManager {
public:
    char pad[0x10];
    int m_sfxFadeOutFlag;
    int pad_14;
    int m_sfxFadeTime;

    void FadeOutSFX(unsigned int time);
};

void cSoundModeManager::FadeOutSFX(unsigned int time) {
    int one = 1;
    *(volatile int*)&m_sfxFadeTime = time;
    *(volatile int*)&m_sfxFadeOutFlag = one;
}
