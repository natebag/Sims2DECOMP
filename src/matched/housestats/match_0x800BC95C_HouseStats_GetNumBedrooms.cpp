// 0x800BC95C HouseStats::GetNumBedrooms (8B)
struct HouseStats {
    char pad[8];
    int m_numBedrooms;
    int GetNumBedrooms();
};

int HouseStats::GetNumBedrooms() { return m_numBedrooms; }
