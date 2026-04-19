/* MotionBlur::EffectIsFinishedFadingIn(float) at 0x803572C0 (24B) */
// 0x803572C0 (24 bytes)

struct MotionBlur_FIFDI {
    float m_fadeInEnd;   // 0
    int EffectIsFinishedFadingIn(float time) const;
};

int MotionBlur_FIFDI::EffectIsFinishedFadingIn(float time) const {
    return time >= m_fadeInEnd;
}
