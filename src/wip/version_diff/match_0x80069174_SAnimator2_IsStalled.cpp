// 0x80069174 SAnimator2::IsStalled (24b)

struct SAnimator2 {
    int m_pendingCount;
    bool IsStalled();
};

bool SAnimator2::IsStalled() {
    return m_pendingCount != 0;
}
