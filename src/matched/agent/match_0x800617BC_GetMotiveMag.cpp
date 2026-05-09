// 0x800617BC GetMotiveMag(float) (72B)
// NaN-coax sibling of ESimsCam::GetCurZoomRatio.
// Maps motive value [-100..100] to [0..1] with NaN-loose upper clamp.
// Unified-return pattern via float result temp.

float GetMotiveMag(float val) {
    float mag = (val + 100.0f) / 200.0f;
    float result;
    if (mag < 0.0f) result = 0.0f;
    else if (!(mag > 1.0f)) result = mag;
    else result = 1.0f;
    return result;
}
