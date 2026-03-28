/* NeighborhoodImpl::GetHouseNumber(void) - 0x800D1294 (8 bytes) */

struct NeighborhoodImpl {
    char m_pad[0x70];
    int m_houseNumber;

    int GetHouseNumber(void);
};

int NeighborhoodImpl::GetHouseNumber(void) {
    return m_houseNumber;
}
