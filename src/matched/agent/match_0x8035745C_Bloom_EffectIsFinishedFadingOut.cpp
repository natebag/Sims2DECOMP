// 0x8035745C (24B) Bloom::EffectIsFinishedFadingOut(float) const
// Return arg >= this->m_fadeOutTime (float at offset 4).

class Bloom {
public:
    float m_fadeInTime;
    float m_fadeOutTime;
    bool EffectIsFinishedFadingOut(float) const;
};

bool Bloom::EffectIsFinishedFadingOut(float t) const {
    return t >= m_fadeOutTime;
}
