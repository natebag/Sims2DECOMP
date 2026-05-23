// 0x800BC964 HouseStats::GetNumBathrooms(void) (8 B)
struct HouseStats { char _pad[0xc]; unsigned m_numBathrooms; unsigned GetNumBathrooms(); };
unsigned HouseStats::GetNumBathrooms() { return m_numBathrooms; }
