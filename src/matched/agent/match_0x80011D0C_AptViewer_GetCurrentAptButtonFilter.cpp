// 0x80011D0C (68B) AptViewer::GetCurrentAptButtonFilter(int)
// Returns int (not pointer). Indexes 2D filter table at +0x3B0 by
// [idx][activeIdx[idx]].a where Entry is {int a, int b}.

class AptViewer_GCF {
public:
    char _pad[936];
    int m_isActive;               // +0x3A8
    int _pad2;                    // +0x3AC
    struct Entry { int a; int b; } m_filters[2][10];  // +0x3B0 (160B)
    int m_activeIdx[2];           // +0x450

    int GetCurrentAptButtonFilter(int idx);
};

int AptViewer_GCF::GetCurrentAptButtonFilter(int idx) {
    if (m_isActive == 0) {
        return -1;
    }
    if ((unsigned)idx > 1) {
        idx = 0;
    }
    int subIdx = m_activeIdx[idx];
    return m_filters[idx][subIdx].a;
}
