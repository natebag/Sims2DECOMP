// 0x800B0EF0 cSoundModeManager::GetDemoMusicTrack (24b)
extern int g_demoMusicTracks[];

struct cSoundModeManager {
    char pad[0x2C];
    int m_demoTrack;
    int GetDemoMusicTrack();
};

int cSoundModeManager::GetDemoMusicTrack() {
    return g_demoMusicTracks[m_demoTrack];
}
