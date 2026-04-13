// 0x80357444 Bloom::EffectIsFinishedFadingIn (24b)

struct Bloom {
    float m_fadeInTarget;
    float m_fadeOutTarget;
    bool EffectIsFinishedFadingIn(float f) const;
};

bool Bloom::EffectIsFinishedFadingIn(float f) const {
    return f >= m_fadeInTarget;
}
