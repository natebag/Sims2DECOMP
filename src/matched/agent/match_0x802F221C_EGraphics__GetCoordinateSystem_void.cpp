// 0x802F221C EGraphics::GetCoordinateSystem(void) (8 B)
struct EGraphics { char _pad[0x98]; unsigned m_field; unsigned GetCoordinateSystem(); };
unsigned EGraphics::GetCoordinateSystem() { return m_field; }
