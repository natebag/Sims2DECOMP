/* DepthOfField::EffectIsFinishedFadingIn(float) at 0x80357628 (24B) */
// 0x80357628 (24 bytes)

struct DepthOfField_FIFDI {
    float m_fadeInEnd;   // 0
    int EffectIsFinishedFadingIn(float time) const;
};

int DepthOfField_FIFDI::EffectIsFinishedFadingIn(float time) const {
    return time >= m_fadeInEnd;
}
