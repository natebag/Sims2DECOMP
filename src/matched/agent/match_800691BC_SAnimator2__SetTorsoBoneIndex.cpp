typedef unsigned char u8;

class SAnimator2 {
    u8 _pad0[0x618];
    int m_nTorsoBoneIndex;
public:
    void SetTorsoBoneIndex(int);
};

void SAnimator2::SetTorsoBoneIndex(int idx) {
    m_nTorsoBoneIndex = idx;
}
