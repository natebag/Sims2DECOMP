/* 0x80069228 (8 bytes) - SAnimator2::SetLastCostume(int) */
struct SAnimator2 {
    char pad[0x130];
    int m_lastCostume;
    void SetLastCostume(int val);
};
void SAnimator2::SetLastCostume(int val) { m_lastCostume = val; }
