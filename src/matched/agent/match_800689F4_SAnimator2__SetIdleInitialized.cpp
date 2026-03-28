typedef unsigned char u8;

class SAnimator2 {
    u8 _pad0[0x120];
    int m_bIdleInitialized;
public:
    void SetIdleInitialized(bool);
};

void SAnimator2::SetIdleInitialized(bool val) {
    m_bIdleInitialized = val;
}
