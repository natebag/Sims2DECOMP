// 0x8030F3BC BSplineVolume::GetID(void) (8 B)
struct BSplineVolume { char _pad[0x80]; unsigned m_field; unsigned GetID(); };
unsigned BSplineVolume::GetID() { return m_field; }
