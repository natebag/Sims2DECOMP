// VERSION_DIFF: branch structure differs (DOL uses conditional returns)
// C++ logic is correct - field layout verified
// 0x802EFD44 (68 bytes)
/* EAnimController::SetTrackSpeed(EACTrack *, float) */

struct EACTrack {
    char _pad[0x30];
    int m_flags;          /* 0x30 */
    char _pad2[0x4C-0x34];
    float m_speed;        /* 0x4C */
    char _pad3[0xA8-0x50];
    int m_state;          /* 0xA8 */
};

struct EAnimController_SetTrackSpeed {
    void SetTrackSpeed(EACTrack* track, float speed);
};

void EAnimController_SetTrackSpeed::SetTrackSpeed(EACTrack* track, float speed) {
    if (track->m_state == 1) {
        if (speed != 0.0f) {
            track->m_flags |= 0x400;
        } else {
            track->m_flags &= ~0x400;
        }
    }
    track->m_speed = speed;
}
