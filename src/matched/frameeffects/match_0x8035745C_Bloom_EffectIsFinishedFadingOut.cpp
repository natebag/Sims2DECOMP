// 0x8035745C Bloom::EffectIsFinishedFadingOut (24b)

struct Bloom {
    float m_fadeInTarget;
    float m_fadeOutTarget;
    bool EffectIsFinishedFadingOut(float f) const;
};

bool Bloom::EffectIsFinishedFadingOut(float f) const {
    return f >= m_fadeOutTarget;
}
