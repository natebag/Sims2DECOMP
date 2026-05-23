/* 0x800690C0 (8 bytes) - SAnimator2::GetRealDir(void) */
struct SAnimator2 {
    char pad[0x30];
    float m_realDir;
    float GetRealDir();
};
float SAnimator2::GetRealDir() { return m_realDir; }
