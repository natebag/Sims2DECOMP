typedef unsigned char u8;

class SAnimator2 {
    u8 _pad0[0xFC];
    float m_fTimeMultiplier;
public:
    float GetTimeMultiplier();
};

float SAnimator2::GetTimeMultiplier() {
    return m_fTimeMultiplier;
}
