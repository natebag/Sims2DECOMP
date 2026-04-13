// 0x800B0488 cSoundModeManager::FadeInSFX (12b)
// FLAGS: -fno-schedule-insns

class cSoundModeManager {
public:
    char pad[0x14];
    int m_sfxFadeInFlag;
    int m_sfxFadeTime;

    void FadeInSFX(unsigned int time);
};

void cSoundModeManager::FadeInSFX(unsigned int time) {
    int one = 1;
    *(volatile int*)&m_sfxFadeTime = time;
    *(volatile int*)&m_sfxFadeInFlag = one;
}
