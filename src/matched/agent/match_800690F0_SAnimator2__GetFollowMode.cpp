typedef unsigned char u8;

class SAnimator2 {
    u8 _pad0[0x18];
    int m_eFollowMode;
public:
    int GetFollowMode();
};

int SAnimator2::GetFollowMode() {
    return m_eFollowMode;
}
