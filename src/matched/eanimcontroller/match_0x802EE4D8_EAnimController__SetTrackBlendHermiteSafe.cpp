/* 0x802EE4D8 (8 bytes) - EAnimController::SetTrackBlendHermiteSafe(EACTrack*, float, float, float, float) */
struct EACTrack;

class EAnimController {
public:
    void SetTrackBlendHermite(EACTrack* track, float a, float b, float c, float d);
    void SetTrackBlendHermiteSafe(EACTrack* track, float a, float b, float c, float d);
};

void EAnimController::SetTrackBlendHermiteSafe(EACTrack* track, float a, float b, float c, float d) {
    SetTrackBlendHermite(track, a, b, c, d);
}
