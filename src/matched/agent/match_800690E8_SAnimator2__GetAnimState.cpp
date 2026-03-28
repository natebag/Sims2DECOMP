typedef unsigned char u8;

class SAnimator2 {
    u8 _pad0[0x2C];
    int m_eAnimState;
public:
    int GetAnimState();
};

int SAnimator2::GetAnimState() {
    return m_eAnimState;
}
