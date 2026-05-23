/* 0x802EF214 (28 bytes) - EAnimController::SetTrackBlendFactors(EACTrack *, float *) */
class EACTrack {
public:
    char pad_0[0x9C];
    float* m_blendFactors;
    char pad_A0[0x08];
    int m_field_A8;
};

class EAnimController {
public:
    void SetTrackBlendFactors(EACTrack* track, float* blendFactors);
};

void EAnimController::SetTrackBlendFactors(EACTrack* track, float* blendFactors) {
    if (!track) return;
    if (track->m_field_A8 != 1) return;
    track->m_blendFactors = blendFactors;
}
