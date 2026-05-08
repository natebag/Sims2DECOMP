// EAnimController::SetTrackSpeed(EACTrack *, float) at 0x802EFD44 (68 bytes)
// Source-coax: DOL has `or. r4,r4,r4; beqlr` early-return null check.

struct EACTrack {
    char _pad[0x30];
    int m_flags;
    char _pad2[0x4C-0x34];
    float m_speed;
    char _pad3[0xA8-0x50];
    int m_state;
};

struct EAnimController_SetTrackSpeed {
    void SetTrackSpeed(EACTrack* track, float speed);
};

void EAnimController_SetTrackSpeed::SetTrackSpeed(EACTrack* track, float speed) {
    if (!track) return;
    if (track->m_state != 1) return;
    if (speed < 0.0f) {
        track->m_flags |= 0x4000000;
    } else {
        track->m_flags &= ~0x4000000;
    }
    track->m_speed = speed;
}
