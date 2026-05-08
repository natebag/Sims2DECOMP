// EAnimController::SetTrackBlendFactors(EACTrack *, float *) at 0x802EF214 (28 bytes)
// Source-coax: DOL has `or. r4,r4,r4; beqlr` early-return null check.

struct EACTrack {
    char _pad[0x9C];
    float* m_blendFactors;
    char _pad2[0xA8-0xA0];
    int m_state;
};

struct EAnimController_SetTrackBlendFactors {
    void SetTrackBlendFactors(EACTrack* track, float* blendFactors);
};

void EAnimController_SetTrackBlendFactors::SetTrackBlendFactors(EACTrack* track, float* blendFactors) {
    if (!track) return;
    if (track->m_state != 1) return;
    track->m_blendFactors = blendFactors;
}
