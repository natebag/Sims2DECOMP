class cSoundModeManager {
public:
    char pad[0x10];
    int m_sfxFadeOutFlag;
    int pad_14;
    int m_sfxFadeTime;

    void FadeOutSFX(unsigned int time);
};

void cSoundModeManager::FadeOutSFX(unsigned int time) {
    m_sfxFadeTime = time;
    m_sfxFadeOutFlag = 1;
}
