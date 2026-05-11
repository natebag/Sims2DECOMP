// 0x802EE17C EAnimController::SetTrackBlend(EACTrack *, float) (96B)
// Pattern: null + state==1 + status-byte dispatch: 0 → SetTrackIntensity(true); 1..2 → SetTrackBlendSmooth.
// status loaded as int from byte; `< 0` check is dead-but-emitted because compiler treats source as int.

class EACTrack {
public:
    char pad_0[14];
    unsigned char m_status;       // 14 (0x0E)
    char pad_15[13];
    float m_field_1C;             // 28 (0x1C)
    float m_field_20;             // 32 (0x20)
    char pad_36[132];
    int m_field_A8;               // 168 (0xA8)
};

class EAnimController {
public:
    void SetTrackBlend(EACTrack* track, float blend);
    void SetTrackIntensity(EACTrack* track, float blend, int flag);
    void SetTrackBlendSmooth(EACTrack* track, float blend, float a, float b);
};

void EAnimController::SetTrackBlend(EACTrack* track, float blend) {
    if (track == 0) return;
    if (track->m_field_A8 != 1) return;
    int status = track->m_status;
    if (status == 0) {
        SetTrackIntensity(track, blend, 1);
        return;
    }
    if (status < 0) return;
    if (status > 2) return;
    SetTrackBlendSmooth(track, blend, track->m_field_1C, track->m_field_20);
}
