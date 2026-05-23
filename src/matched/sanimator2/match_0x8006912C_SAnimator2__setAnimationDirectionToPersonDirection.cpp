/* 0x8006912C (48 bytes) - SAnimator2::setAnimationDirectionToPersonDirection(void) */
struct SAnimator2 {
    char pad[0x30];
    float m_realDir;
    float getPersonDirection();
    void setAnimationDirectionToPersonDirection();
};

void SAnimator2::setAnimationDirectionToPersonDirection() {
    m_realDir = getPersonDirection();
}
