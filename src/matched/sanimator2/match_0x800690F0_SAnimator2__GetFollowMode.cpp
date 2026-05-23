/* 0x800690F0 (8 bytes) - SAnimator2::GetFollowMode(void) */
struct SAnimator2 {
    char pad[0x18];
    int m_followMode;
    int GetFollowMode();
};
int SAnimator2::GetFollowMode() { return m_followMode; }
