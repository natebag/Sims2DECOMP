/* cSoundModeManager::FadeInMusic(unsigned int) at 0x800B0468 (16B) */

struct cSoundModeManager {
    char pad[0x08];
    int m_fadeInMusic;
    int m_fadeDuration;

    void FadeInMusic(unsigned int duration);
};

void cSoundModeManager::FadeInMusic(unsigned int duration) {
    m_fadeInMusic = 1;
    m_fadeDuration = duration;
}
