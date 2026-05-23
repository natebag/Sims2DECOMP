/* 0x800691D4 (8 bytes) - SAnimator2::GetRightHandBoneIndex(void) */
struct SAnimator2 {
    char pad[0x60C];
    int m_rightHandBoneIdx;
    int GetRightHandBoneIndex();
};
int SAnimator2::GetRightHandBoneIndex() { return m_rightHandBoneIdx; }
