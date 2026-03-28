/* GetNumNghSubSections(NghLayout *) - 0x800D26F8 (8 bytes) */

struct NghLayout {
    char m_pad[0x0C];
    int m_numSubSections;
};

int GetNumNghSubSections(NghLayout *layout) {
    return layout->m_numSubSections;
}
