/* cSoundModeManager::NextFrontEndTrack(void) at 0x800B0E70 (32B) */

struct cSoundModeManager {
    char pad[0x28];    // 0x00-0x27
    int m_trackIndex;  // 0x28
    
    void NextFrontEndTrack(void);
};

void cSoundModeManager::NextFrontEndTrack(void) {
    int next = m_trackIndex + 1;
    if (next >= 3) {
        next = 0;
    }
    m_trackIndex = next;
}
