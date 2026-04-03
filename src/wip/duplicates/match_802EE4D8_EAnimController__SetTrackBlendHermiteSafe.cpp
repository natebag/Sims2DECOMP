class EACTrack;
class EAnimController {
public:
    void SetTrackBlendHermite(EACTrack *, float, float, float, float);
    void SetTrackBlendHermiteSafe(EACTrack *, float, float, float, float);
};
void EAnimController::SetTrackBlendHermiteSafe(EACTrack *track, float a, float b, float c, float d) {
    SetTrackBlendHermite(track, a, b, c, d);
}
