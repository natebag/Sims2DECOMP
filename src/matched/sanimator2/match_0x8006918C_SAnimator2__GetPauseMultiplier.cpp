/* 0x8006918C (8 bytes) - SAnimator2::GetPauseMultiplier(void) */
struct SAnimator2 {
    char pad[0x104];
    float m_pauseMultiplier;
    float GetPauseMultiplier();
};
float SAnimator2::GetPauseMultiplier() { return m_pauseMultiplier; }
