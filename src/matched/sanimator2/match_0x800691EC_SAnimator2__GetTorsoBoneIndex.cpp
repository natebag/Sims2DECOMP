/* 0x800691EC (8 bytes) - SAnimator2::GetTorsoBoneIndex(void) */
struct SAnimator2 {
    char pad[0x618];
    int m_torsoBoneIdx;
    int GetTorsoBoneIndex();
};
int SAnimator2::GetTorsoBoneIndex() { return m_torsoBoneIdx; }
