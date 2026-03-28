typedef unsigned char u8;

class SAnimator2 {
public:
    typedef int eAnimState;
    u8 _pad0[0xB0];
    eAnimState m_eDesiredAnimState;
    void SetDesiredAnimState(eAnimState);
};

void SAnimator2::SetDesiredAnimState(eAnimState state) {
    m_eDesiredAnimState = state;
}
