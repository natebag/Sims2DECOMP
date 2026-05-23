/* 0x8006B4D0 (92 bytes) - SAnimator2::getSidestepIntensity(void) */
extern "C" float sinf(float);

struct SAnimator2 {
    char pad[0x110];
    float m_field110;
    float getSidestepIntensity();
};

float SAnimator2::getSidestepIntensity() {
    float val = sinf(m_field110);
    val = val * val;
    if (val < 0.0001f) val = 0.0f;
    else if (val > 0.9999f) val = 1.0f;
    return val;
}
