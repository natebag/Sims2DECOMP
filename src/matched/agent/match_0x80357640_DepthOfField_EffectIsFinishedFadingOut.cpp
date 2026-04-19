// 0x80357640 (24B) DepthOfField::EffectIsFinishedFadingOut(float) const
// Return arg >= this->m_fadeOutTime (float at offset 4).

class DepthOfField {
public:
    float m_fadeInTime;
    float m_fadeOutTime;
    bool EffectIsFinishedFadingOut(float) const;
};

bool DepthOfField::EffectIsFinishedFadingOut(float t) const {
    return t >= m_fadeOutTime;
}
