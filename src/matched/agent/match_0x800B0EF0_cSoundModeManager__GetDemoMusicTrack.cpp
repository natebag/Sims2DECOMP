/* cSoundModeManager::GetDemoMusicTrack(void) at 0x800B0EF0 (24B) */
// 0x800B0EF0 (24 bytes)

extern int s_frontEndTracks[];

struct cSoundModeManager_GDMT {
    char _pad[44];          // 0x2C = 44
    int m_demoMusicIndex;   // 0x2C
    int GetDemoMusicTrack() const;
};

int cSoundModeManager_GDMT::GetDemoMusicTrack() const {
    return s_frontEndTracks[m_demoMusicIndex];
}
