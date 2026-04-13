/* NeighborhoodImpl::GetNumNeighborHouses(void) - 0x800D1928 (20 bytes) */

struct NeighborhoodImpl {
    char m_pad[0x4C];
    int *m_housesBegin;
    int *m_housesEnd;

    int GetNumNeighborHouses(void);
};

int NeighborhoodImpl::GetNumNeighborHouses(void) {
    return m_housesEnd - m_housesBegin;
}
