// 0x802EBFD8 EAnimController::StopAllTracks(void) (96B)
// Iterate m_trackArray (each 176B), call DeactivateTrack on each.
// Loop reloads count + array_ptr each iteration (alias-safe — DeactivateTrack
// could modify the array). First-try MATCH.

struct EACTrack;

struct EAnimController {
    char pad[64];
    int m_trackCount;
    EACTrack* m_trackArrayPtr;
    void StopAllTracks();
    void DeactivateTrack(EACTrack* track);
};

void EAnimController::StopAllTracks() {
    for (int i = 0; i < m_trackCount; i++) {
        EACTrack* track = (EACTrack*)((char*)m_trackArrayPtr + i * 176);
        DeactivateTrack(track);
    }
}
