// 0x800BC454 HouseStats::GetSquareFeet(void) (8 B)
struct HouseStats { unsigned m_squareFeet; unsigned GetSquareFeet(); };
unsigned HouseStats::GetSquareFeet() { return m_squareFeet; }
