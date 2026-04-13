// 0x800B0E70 cSoundModeManager::NextFrontEndTrack (32b)
struct cSoundModeManager {
    char pad[0x28];
    int m_frontEndTrack;
    void NextFrontEndTrack();
};

void cSoundModeManager::NextFrontEndTrack() {
    m_frontEndTrack++;
    if (m_frontEndTrack <= 3) return;
    m_frontEndTrack = 0;
}
