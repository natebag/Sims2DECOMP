/* 0x800691B4 (8 bytes) - SAnimator2::SetPelvisBoneIndex(int) */
struct SAnimator2 {
    char pad[0x614];
    int m_pelvisBoneIdx;
    void SetPelvisBoneIndex(int idx);
};
void SAnimator2::SetPelvisBoneIndex(int idx) { m_pelvisBoneIdx = idx; }
