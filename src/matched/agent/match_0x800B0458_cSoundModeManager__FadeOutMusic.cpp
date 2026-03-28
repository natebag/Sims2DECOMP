/* cSoundModeManager::FadeOutMusic(unsigned int) at 0x800B0458 (16B) */

struct cSoundModeManager {
    char pad[0x04];
    int m_fadeOutMusic;
    char pad2[0x00];
    int m_fadeInMusic;
    int m_fadeDuration;

    void FadeOutMusic(unsigned int duration);
};

void cSoundModeManager::FadeOutMusic(unsigned int duration) {
    m_fadeOutMusic = 1;
    m_fadeDuration = duration;
}
