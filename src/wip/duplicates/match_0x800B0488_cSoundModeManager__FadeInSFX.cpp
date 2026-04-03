/* cSoundModeManager::FadeInSFX(unsigned int) at 0x800B0488 (16B) */

struct cSoundModeManager {
    char pad[0x14];
    int m_fadeInSFX;
    int m_sfxFadeDuration;

    void FadeInSFX(unsigned int duration);
};

void cSoundModeManager::FadeInSFX(unsigned int duration) {
    m_fadeInSFX = 1;
    m_sfxFadeDuration = duration;
}
