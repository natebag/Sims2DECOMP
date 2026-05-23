/* 0x800655A4 (48 bytes) - SAnimator2::convertAnimationFormatToEngineFormat(EVec3 &, EVec3 &) */
struct EVec3 { float x, y, z; };

struct SAnimator2 {
    void convertAnimationFormatToEngineFormat(EVec3& src, EVec3& dst);
};

void SAnimator2::convertAnimationFormatToEngineFormat(EVec3& src, EVec3& dst) {
    float ty = src.y;
    ty = ty * 0.0625f;
    dst.x = ty;
    float tx = src.x;
    dst.z = 0.0f;
    dst.y = tx * 0.0625f;
}
