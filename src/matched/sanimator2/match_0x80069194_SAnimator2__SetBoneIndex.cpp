/* 0x80069194 (16 bytes) - SAnimator2::SetBoneIndex(int, int) */
class SAnimator2 {
public:
    char pad[0x60C];
    int m_boneIndex[1];
    void SetBoneIndex(int idx, int val);
};

void SAnimator2::SetBoneIndex(int idx, int val) {
    m_boneIndex[idx] = val;
}
