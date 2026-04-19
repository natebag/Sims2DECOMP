/* SAnimator2::setAnimationDirectionToPersonDirection(void) at 0x8006912C (48B) */

struct SAnimator2_SADTPD {
    char m_pad[48];
    float m_direction;
    float getPersonDirection();
    void setAnimationDirectionToPersonDirection();
};

void SAnimator2_SADTPD::setAnimationDirectionToPersonDirection() {
    m_direction = getPersonDirection();
}
