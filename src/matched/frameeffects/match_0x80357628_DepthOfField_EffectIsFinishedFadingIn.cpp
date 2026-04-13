// 0x80357628 DepthOfField::EffectIsFinishedFadingIn (24b)

struct DepthOfField {
    float m_fadeInTarget;
    float m_fadeOutTarget;
    bool EffectIsFinishedFadingIn(float f) const;
};

bool DepthOfField::EffectIsFinishedFadingIn(float f) const {
    return f >= m_fadeInTarget;
}
