/* cSoundModeManager::NextFrontEndTrack(void) at 0x800B0E70 (32B) */
// 0x800B0E70 (32 bytes)

struct cSoundModeManager_NFET {
    char _pad[40];
    int m_frontEndTrack;  // 40 = 0x28
    void NextFrontEndTrack();
};

void cSoundModeManager_NFET::NextFrontEndTrack() {
    int track = m_frontEndTrack + 1;
    m_frontEndTrack = track;
    if (track <= 3) return;
    m_frontEndTrack = 0;
}
