/* 0x800690D0 (8 bytes) - SAnimator2::GetTimeMultiplier(void) */
struct SAnimator2 {
    char pad[0xFC];
    float m_timeMultiplier;
    float GetTimeMultiplier();
};
float SAnimator2::GetTimeMultiplier() { return m_timeMultiplier; }
