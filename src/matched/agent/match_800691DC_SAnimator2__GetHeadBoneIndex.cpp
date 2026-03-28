typedef unsigned char u8;

class SAnimator2 {
    u8 _pad0[0x610];
    int m_nHeadBoneIndex;
public:
    int GetHeadBoneIndex();
};

int SAnimator2::GetHeadBoneIndex() {
    return m_nHeadBoneIndex;
}
