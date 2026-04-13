// 0x80357640 DepthOfField::EffectIsFinishedFadingOut (24b)

struct DepthOfField {
    float m_fadeInTarget;
    float m_fadeOutTarget;
    bool EffectIsFinishedFadingOut(float f) const;
};

bool DepthOfField::EffectIsFinishedFadingOut(float f) const {
    return f >= m_fadeOutTarget;
}
