/* 0x800689F4 (8 bytes) - SAnimator2::SetIdleInitialized(bool) */
struct SAnimator2 {
    char pad[0x120];
    int m_idleInitialized;
    void SetIdleInitialized(bool val);
};
void SAnimator2::SetIdleInitialized(bool val) {
    m_idleInitialized = val;
}
