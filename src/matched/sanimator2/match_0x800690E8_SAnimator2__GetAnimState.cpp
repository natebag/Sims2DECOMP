/* 0x800690E8 (8 bytes) - SAnimator2::GetAnimState(void) */
struct SAnimator2 {
    char pad[0x2C];
    int m_animState;
    int GetAnimState();
};
int SAnimator2::GetAnimState() { return m_animState; }
