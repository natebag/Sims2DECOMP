typedef unsigned char u8;

class SAnimator2 {
    u8 _pad0[0x30];
    float m_fRealDir;
public:
    float GetRealDir();
};

float SAnimator2::GetRealDir() {
    return m_fRealDir;
}
