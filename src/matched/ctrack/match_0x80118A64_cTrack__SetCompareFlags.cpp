// 0x80118A64 cTrack::SetCompareFlags(int, int) (44B)
// Single cmpw + three mfcr/rlwinm flag extractions.

struct cTrack {
    char pad[60];
    int m_eq;  // offset 60
    int m_gt;  // offset 64
    int m_lt;  // offset 68
    void SetCompareFlags(int a, int b);
};

void cTrack::SetCompareFlags(int a, int b) {
    m_eq = (a == b);
    m_gt = (a > b);
    m_lt = (a < b);
}
