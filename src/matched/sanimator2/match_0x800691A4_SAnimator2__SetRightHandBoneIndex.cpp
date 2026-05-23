/* 0x800691A4 (8 bytes) - SAnimator2::SetRightHandBoneIndex(int) */
struct SAnimator2 {
    char pad[0x60C];
    int m_rightHandBoneIdx;
    void SetRightHandBoneIndex(int idx);
};
void SAnimator2::SetRightHandBoneIndex(int idx) { m_rightHandBoneIdx = idx; }
