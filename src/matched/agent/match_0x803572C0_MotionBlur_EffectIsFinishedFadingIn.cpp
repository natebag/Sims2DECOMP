// 0x803572C0 (24B) MotionBlur::EffectIsFinishedFadingIn(float) const
// Return arg >= this->m_fadeInTime (float at offset 0).

class MotionBlur {
public:
    float m_fadeInTime;
    bool EffectIsFinishedFadingIn(float) const;
};

bool MotionBlur::EffectIsFinishedFadingIn(float t) const {
    return t >= m_fadeInTime;
}
