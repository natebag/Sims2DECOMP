// FLAGS: -msdata=eabi -G 8
/* 0x800698E4 (60 bytes) - SAnimator2::setFollowMiddle(void) */
extern void setMovementVelocityFromAnim(void*);

struct SAnimator2 {
    char pad[0x18];
    int m_followMode;
    char pad2[0x600];
    int m_stateFlags;
    void setFollowMiddle();
};

void SAnimator2::setFollowMiddle() {
    m_followMode = 3;
    m_stateFlags = m_stateFlags & ~0x5E;
    setMovementVelocityFromAnim(this);
}
