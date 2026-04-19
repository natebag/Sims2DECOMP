// 0x80357628 (24B) DepthOfField::EffectIsFinishedFadingIn(float) const
// Return arg >= this->m_fadeInTime (float at offset 0).

class DepthOfField {
public:
    float m_fadeInTime;
    bool EffectIsFinishedFadingIn(float) const;
};

bool DepthOfField::EffectIsFinishedFadingIn(float t) const {
    return t >= m_fadeInTime;
}
