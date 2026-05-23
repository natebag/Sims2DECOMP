/* 0x80069220 (8 bytes) - SAnimator2::GetLastCostume(void) */
struct SAnimator2 {
    char pad[0x130];
    int m_lastCostume;
    int GetLastCostume();
};
int SAnimator2::GetLastCostume() { return m_lastCostume; }
