// FLAGS: -fno-schedule-insns
// 0x80011D0C (68 bytes)
// AptViewer::GetCurrentAptButtonFilter(int)

struct AptButtonFilter { char data[8]; };

struct AptViewer_GCF {
    char pad936[936];
    void* m_validFlag;    // offset 936
    char pad940[4];
    AptButtonFilter m_filters[2][10]; // offset 944, 2 filter types * 10 entries * 8B = 160B
    char pad1104[0];
    int m_currentIdx[2];  // offset 1104, 2 entries * 4B
    AptButtonFilter* GetCurrentAptButtonFilter(int filter_type);
};

AptButtonFilter* AptViewer_GCF::GetCurrentAptButtonFilter(int filter_type) {
    if (!m_validFlag) return (AptButtonFilter*)-1;
    if ((unsigned int)filter_type > 1u) filter_type = 0;
    int idx = m_currentIdx[filter_type];
    return &m_filters[filter_type][idx];
}
