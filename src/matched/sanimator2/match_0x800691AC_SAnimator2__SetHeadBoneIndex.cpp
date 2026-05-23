/* 0x800691AC (8 bytes) - SAnimator2::SetHeadBoneIndex(int) */
struct SAnimator2 {
    char pad[0x610];
    int m_headBoneIdx;
    void SetHeadBoneIndex(int idx);
};
void SAnimator2::SetHeadBoneIndex(int idx) { m_headBoneIdx = idx; }
