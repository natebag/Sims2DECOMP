/* 0x802EBFD8 (96 bytes) - EAnimController::StopAllTracks(void) */
class EACTrack;

class EAnimController {
public:
    char pad_0[64];
    int m_trackCount;
    EACTrack* m_trackArrayPtr;

    void DeactivateTrack(EACTrack* track);
    void StopAllTracks();
};

void EAnimController::StopAllTracks() {
    for (int i = 0; i < m_trackCount; i++) {
        EACTrack* track = (EACTrack*)((char*)m_trackArrayPtr + i * 176);
        DeactivateTrack(track);
    }
}
