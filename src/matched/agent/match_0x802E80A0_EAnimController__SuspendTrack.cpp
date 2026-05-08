// EAnimController::SuspendTrack(EACTrack *) at 0x802E80A0 (36 bytes)
// Source-coax: same null-check + state-check + flag-OR pattern as SetTrackSpeed.

struct EACTrack {
    char _pad[0x30];
    int m_flags;
    char _pad2[0xA8-0x34];
    int m_state;
};

struct EAnimController_SuspendTrack {
    void SuspendTrack(EACTrack* track);
};

void EAnimController_SuspendTrack::SuspendTrack(EACTrack* track) {
    if (!track) return;
    if (track->m_state != 1) return;
    track->m_flags |= 0x08000000;
}
