// 0x803572D8 (24B) MotionBlur::EffectIsFinishedFadingOut(float) const
// Return arg >= this->m_fadeOutTime (float at offset 4).

class MotionBlur {
public:
    float m_fadeInTime;
    float m_fadeOutTime;
    bool EffectIsFinishedFadingOut(float) const;
};

bool MotionBlur::EffectIsFinishedFadingOut(float t) const {
    return t >= m_fadeOutTime;
}
