/* MotionBlur::EffectIsFinishedFadingOut(float) at 0x803572D8 (24B) */
// 0x803572D8 (24 bytes)

struct MotionBlur_FIFDO {
    char _pad[4];
    float m_fadeOutEnd;  // 4
    int EffectIsFinishedFadingOut(float time) const;
};

int MotionBlur_FIFDO::EffectIsFinishedFadingOut(float time) const {
    return time >= m_fadeOutEnd;
}
