/* DepthOfField::EffectIsFinishedFadingOut(float) at 0x80357640 (24B) */
// 0x80357640 (24 bytes)

struct DepthOfField_FIFDO {
    char _pad[4];
    float m_fadeOutEnd;  // 4
    int EffectIsFinishedFadingOut(float time) const;
};

int DepthOfField_FIFDO::EffectIsFinishedFadingOut(float time) const {
    return time >= m_fadeOutEnd;
}
