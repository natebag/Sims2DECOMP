// 0x800BC95C HouseStats::GetNumBedrooms(void) (8 B)
struct HouseStats { char _pad[0x8]; unsigned m_numBedrooms; unsigned GetNumBedrooms(); };
unsigned HouseStats::GetNumBedrooms() { return m_numBedrooms; }
