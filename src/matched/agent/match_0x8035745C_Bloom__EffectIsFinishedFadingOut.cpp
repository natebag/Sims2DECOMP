/* Bloom::EffectIsFinishedFadingOut(float) at 0x8035745C (24B) */
// 0x8035745C (24 bytes)

struct Bloom_FIFDO {
    char _pad[4];
    float m_fadeOutEnd;  // 4
    int EffectIsFinishedFadingOut(float time) const;
};

int Bloom_FIFDO::EffectIsFinishedFadingOut(float time) const {
    return time >= m_fadeOutEnd;
}
