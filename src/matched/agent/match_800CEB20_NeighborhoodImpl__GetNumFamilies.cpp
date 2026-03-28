/* NeighborhoodImpl::GetNumFamilies(void) - 0x800CEB20 (20 bytes) */

struct NeighborhoodImpl {
    char m_pad[0x5C];
    int *m_familiesBegin;
    int *m_familiesEnd;

    int GetNumFamilies(void);
};

int NeighborhoodImpl::GetNumFamilies(void) {
    return m_familiesEnd - m_familiesBegin;
}
