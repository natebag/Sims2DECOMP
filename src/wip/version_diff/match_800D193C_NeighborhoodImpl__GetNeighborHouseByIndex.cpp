/* NeighborhoodImpl::GetNeighborHouseByIndex(int) - 0x800D193C (16 bytes) */

struct NeighborhoodImpl {
    char m_pad[0x4C];
    int *m_neighborHouses;

    int GetNeighborHouseByIndex(int index);
};

int NeighborhoodImpl::GetNeighborHouseByIndex(int index) {
    return *(int *)((char *)m_neighborHouses + (index << 2));
}
