// 0x800BC974 HouseStats::GetLotSize (8B)
struct HouseStats {
    char pad[20];
    int m_lotSize;
    int GetLotSize();
};

int HouseStats::GetLotSize() { return m_lotSize; }
