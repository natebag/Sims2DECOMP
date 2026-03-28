typedef unsigned char u8;

class SAnimator2 {
    u8 _pad0[0x614];
    int m_nPelvisBoneIndex;
public:
    void SetPelvisBoneIndex(int);
};

void SAnimator2::SetPelvisBoneIndex(int idx) {
    m_nPelvisBoneIndex = idx;
}
