struct EACTrack;

struct EAnimController {
    void SetTrackBlendHermite(EACTrack* track, float a, float b, float c, float d);
    void SetTrackBlendHermiteSafe(EACTrack* track, float a, float b, float c, float d);
};

void EAnimController::SetTrackBlendHermiteSafe(EACTrack* track, float a, float b, float c, float d)
{
    SetTrackBlendHermite(track, a, b, c, d);
}
