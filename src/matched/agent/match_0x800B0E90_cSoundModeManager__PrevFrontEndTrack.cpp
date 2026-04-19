/* cSoundModeManager::PrevFrontEndTrack(void) at 0x800B0E90 (32B) */
// 0x800B0E90 (32 bytes)

struct cSoundModeManager_PFET {
    char _pad[40];
    int m_frontEndTrack;  // 40 = 0x28
    void PrevFrontEndTrack();
};

void cSoundModeManager_PFET::PrevFrontEndTrack() {
    int track = m_frontEndTrack - 1;
    m_frontEndTrack = track;
    if (track >= 0) return;
    m_frontEndTrack = 3;
}
