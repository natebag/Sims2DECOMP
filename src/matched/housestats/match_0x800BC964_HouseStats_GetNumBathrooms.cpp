// 0x800BC964 HouseStats::GetNumBathrooms (8B)
struct HouseStats {
    char pad[12];
    int m_numBathrooms;
    int GetNumBathrooms();
};

int HouseStats::GetNumBathrooms() { return m_numBathrooms; }
