// 0x800B0F08 cSoundModeManager::NextDemoMusicTrack (32b)
struct cSoundModeManager {
    char pad[0x2C];
    int m_demoMusicTrack;
    void NextDemoMusicTrack();
};

void cSoundModeManager::NextDemoMusicTrack() {
    m_demoMusicTrack++;
    if (m_demoMusicTrack <= 2) return;
    m_demoMusicTrack = 1;
}
