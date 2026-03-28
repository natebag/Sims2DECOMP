typedef unsigned char u8;

class SAnimator2 {
    u8 _pad0[0x614];
    int m_nPelvisBoneIndex;
public:
    int GetPelvisBoneIndex();
};

int SAnimator2::GetPelvisBoneIndex() {
    return m_nPelvisBoneIndex;
}
