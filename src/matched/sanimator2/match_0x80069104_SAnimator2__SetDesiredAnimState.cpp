/* 0x80069104 (8 bytes) - SAnimator2::SetDesiredAnimState(SAnimator2::eAnimState) */
struct SAnimator2 {
    char pad[0xB0];
    int m_desiredAnimState;
    void SetDesiredAnimState(int state);
};
void SAnimator2::SetDesiredAnimState(int state) { m_desiredAnimState = state; }
