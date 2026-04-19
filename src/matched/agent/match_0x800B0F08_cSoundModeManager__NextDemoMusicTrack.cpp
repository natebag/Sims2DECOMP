/* cSoundModeManager::NextDemoMusicTrack(void) at 0x800B0F08 (32B) */
// 0x800B0F08 (32 bytes)

struct cSoundModeManager_NDMT {
    char _pad[44];
    int m_demoMusicIndex;  // 0x2C = 44
    void NextDemoMusicTrack();
};

void cSoundModeManager_NDMT::NextDemoMusicTrack() {
    int track = m_demoMusicIndex + 1;
    m_demoMusicIndex = track;
    if (track <= 2) return;
    m_demoMusicIndex = 1;
}
