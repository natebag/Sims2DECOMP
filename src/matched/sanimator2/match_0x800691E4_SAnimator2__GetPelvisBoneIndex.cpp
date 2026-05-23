/* 0x800691E4 (8 bytes) - SAnimator2::GetPelvisBoneIndex(void) */
struct SAnimator2 {
    char pad[0x614];
    int m_pelvisBoneIdx;
    int GetPelvisBoneIndex();
};
int SAnimator2::GetPelvisBoneIndex() { return m_pelvisBoneIdx; }
