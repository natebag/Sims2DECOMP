/* 0x800691BC (8 bytes) - SAnimator2::SetTorsoBoneIndex(int) */
struct SAnimator2 {
    char pad[0x618];
    int m_torsoBoneIdx;
    void SetTorsoBoneIndex(int idx);
};
void SAnimator2::SetTorsoBoneIndex(int idx) { m_torsoBoneIdx = idx; }
