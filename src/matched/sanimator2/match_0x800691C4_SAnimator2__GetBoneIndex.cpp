/* 0x800691C4 (16 bytes) - SAnimator2::GetBoneIndex(int) */
class SAnimator2 {
public:
    char pad[0x60C];
    int m_boneIndex[1];
    int GetBoneIndex(int idx);
};

int SAnimator2::GetBoneIndex(int idx) {
    return m_boneIndex[idx];
}
