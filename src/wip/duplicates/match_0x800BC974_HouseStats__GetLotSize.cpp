/* HouseStats::GetLotSize(void) at 0x800BC974 (8B) */

struct HouseStats {
    char pad[0x14];
    int m_lotSize;

    int GetLotSize(void);
};

int HouseStats::GetLotSize(void) {
    return m_lotSize;
}
