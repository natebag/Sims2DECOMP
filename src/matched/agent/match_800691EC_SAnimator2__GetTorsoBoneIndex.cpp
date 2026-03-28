typedef unsigned char u8;

class SAnimator2 {
    u8 _pad0[0x618];
    int m_nTorsoBoneIndex;
public:
    int GetTorsoBoneIndex();
};

int SAnimator2::GetTorsoBoneIndex() {
    return m_nTorsoBoneIndex;
}
