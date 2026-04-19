// 0x80357444 (24B) Bloom::EffectIsFinishedFadingIn(float) const
// Return arg >= this->m_fadeInTime (float at offset 0).

class Bloom {
public:
    float m_fadeInTime;
    bool EffectIsFinishedFadingIn(float) const;
};

bool Bloom::EffectIsFinishedFadingIn(float t) const {
    return t >= m_fadeInTime;
}
