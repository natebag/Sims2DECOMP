/* 0x802E80A0 (36 bytes) - EAnimController::SuspendTrack(EACTrack*) */
class EACTrack {
public:
    char pad_0[0x30];
    int m_flags;
    char pad_34[0x74];
    int m_field_A8;
};

class EAnimController {
public:
    void SuspendTrack(EACTrack* track);
};

void EAnimController::SuspendTrack(EACTrack* track) {
    if (!track) return;
    if (track->m_field_A8 != 1) return;
    track->m_flags |= 0x08000000;
}
