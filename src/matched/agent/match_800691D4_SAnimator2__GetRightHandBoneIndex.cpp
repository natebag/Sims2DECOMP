typedef unsigned char u8;

class SAnimator2 {
    u8 _pad0[0x60C];
    int m_nRightHandBoneIndex;
public:
    int GetRightHandBoneIndex();
};

int SAnimator2::GetRightHandBoneIndex() {
    return m_nRightHandBoneIndex;
}
