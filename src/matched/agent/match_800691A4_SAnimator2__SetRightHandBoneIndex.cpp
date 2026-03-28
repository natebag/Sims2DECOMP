typedef unsigned char u8;

class SAnimator2 {
    u8 _pad0[0x60C];
    int m_nRightHandBoneIndex;
public:
    void SetRightHandBoneIndex(int);
};

void SAnimator2::SetRightHandBoneIndex(int idx) {
    m_nRightHandBoneIndex = idx;
}
