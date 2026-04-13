/* NeighborhoodImpl::SetHouseNum(int) - 0x800D1950 (8 bytes) */

struct NeighborhoodImpl {
    char m_pad[0x70];
    int m_houseNumber;

    void SetHouseNum(int num);
};

void NeighborhoodImpl::SetHouseNum(int num) {
    m_houseNumber = num;
}
