typedef unsigned char u8;

class SAnimator2 {
    u8 _pad0[0x104];
    float m_fPauseMultiplier;
public:
    float GetPauseMultiplier();
};

float SAnimator2::GetPauseMultiplier() {
    return m_fPauseMultiplier;
}
