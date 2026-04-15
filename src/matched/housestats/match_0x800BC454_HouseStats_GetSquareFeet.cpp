// 0x800BC454 HouseStats::GetSquareFeet (8B)
struct HouseStats {
    int m_squareFeet;
    int GetSquareFeet();
};

int HouseStats::GetSquareFeet() { return m_squareFeet; }
