/* 0x800691DC (8 bytes) - SAnimator2::GetHeadBoneIndex(void) */
struct SAnimator2 {
    char pad[0x610];
    int m_headBoneIdx;
    int GetHeadBoneIndex();
};
int SAnimator2::GetHeadBoneIndex() { return m_headBoneIdx; }
