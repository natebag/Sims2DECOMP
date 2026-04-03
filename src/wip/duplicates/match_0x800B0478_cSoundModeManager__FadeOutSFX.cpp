/* cSoundModeManager::FadeOutSFX(unsigned int) at 0x800B0478 (16B) */

struct cSoundModeManager {
    char pad[0x10];
    int m_fadeOutSFX;
    char pad2[0x04];
    int m_sfxFadeDuration;

    void FadeOutSFX(unsigned int duration);
};

void cSoundModeManager::FadeOutSFX(unsigned int duration) {
    m_fadeOutSFX = 1;
    m_sfxFadeDuration = duration;
}
