/* Bloom::EffectIsFinishedFadingIn(float) at 0x80357444 (24B) */
// 0x80357444 (24 bytes)

struct Bloom_FIFDI {
    float m_fadeInEnd;   // 0
    int EffectIsFinishedFadingIn(float time) const;
};

int Bloom_FIFDI::EffectIsFinishedFadingIn(float time) const {
    return time >= m_fadeInEnd;
}
