// 0x800BC96C HouseStats::GetNumLevels (8B)
struct HouseStats {
    char pad[16];
    int m_numLevels;
    int GetNumLevels();
};

int HouseStats::GetNumLevels() { return m_numLevels; }
