// 0x800D26F8 GetNumNghSubSections (8B)
struct NghLayout {
    char pad[12];
    int m_numSubSections;
};

int GetNumNghSubSections(NghLayout* l) { return l->m_numSubSections; }
