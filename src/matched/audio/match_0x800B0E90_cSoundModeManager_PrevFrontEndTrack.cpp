// 0x800B0E90 cSoundModeManager::PrevFrontEndTrack (32b)
struct cSoundModeManager {
    char pad[0x28];
    int m_frontEndTrack;
    void PrevFrontEndTrack();
};

void cSoundModeManager::PrevFrontEndTrack() {
    m_frontEndTrack--;
    if (m_frontEndTrack >= 0) return;
    m_frontEndTrack = 3;
}
