/* 0x802EFD44 (68 bytes) - EAnimController::SetTrackSpeed(EACTrack *, float) */
class EACTrack {
public:
    char pad_0[0x30];
    int m_flags;
    char pad_34[0x18];
    float m_speed;
    char pad_50[0x58];
    int m_field_A8;
};

class EAnimController {
public:
    void SetTrackSpeed(EACTrack* track, float speed);
};

void EAnimController::SetTrackSpeed(EACTrack* track, float speed) {
    if (!track) return;
    if (track->m_field_A8 != 1) return;
    if (speed < 0.0f) {
        track->m_flags |= 0x4000000;
    } else {
        track->m_flags &= ~0x4000000;
    }
    track->m_speed = speed;
}
