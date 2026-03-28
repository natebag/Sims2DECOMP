typedef unsigned char u8;

class SAnimator2 {
    u8 _pad0[0x610];
    int m_nHeadBoneIndex;
public:
    void SetHeadBoneIndex(int);
};

void SAnimator2::SetHeadBoneIndex(int idx) {
    m_nHeadBoneIndex = idx;
}
