class cSoundModeManager {
public:
    char pad[0x14];
    int m_sfxFadeInFlag;
    int m_sfxFadeTime;

    void FadeInSFX(unsigned int time);
};

void cSoundModeManager::FadeInSFX(unsigned int time) {
    m_sfxFadeTime = time;
    m_sfxFadeInFlag = 1;
}
