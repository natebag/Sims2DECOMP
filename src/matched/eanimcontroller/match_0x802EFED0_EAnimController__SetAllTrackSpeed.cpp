// 0x802EFED0 EAnimController::SetAllTrackSpeed(float) (104B)
// Pattern: loop over m_tracks (176B stride) — for each, if track flag bit 0x04000000 is set,
// store -speed when speed > 0 else speed; if bit not set, inverse. Sign-flip XOR-with-flag pattern.

class EACTrack {
public:
    char pad_0[48];
    int m_field_30;          // 48 (0x30)
    char pad_52[24];
    float m_speed;           // 76 (0x4C)
};

class EAnimController {
public:
    char pad_0[64];
    int m_trackCount;        // 64 (0x40)
    EACTrack* m_tracks;      // 68 (0x44)

    void SetAllTrackSpeed(float speed);
};

void EAnimController::SetAllTrackSpeed(float speed) {
    for (int i = 0; i < m_trackCount; i++) {
        EACTrack* track = (EACTrack*)(i * 176 + (unsigned int)m_tracks);
        if (track->m_field_30 & 0x04000000) {
            if (speed > 0.0f) {
                track->m_speed = -speed;
            } else {
                track->m_speed = speed;
            }
        } else {
            if (speed > 0.0f) {
                track->m_speed = speed;
            } else {
                track->m_speed = -speed;
            }
        }
    }
}
