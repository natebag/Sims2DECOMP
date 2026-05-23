// 0x802F2358 EGraphics::IsInsideBeginEnd(void) (8 B)
struct EGraphics { char _pad[0x4]; unsigned m_field; unsigned IsInsideBeginEnd(); };
unsigned EGraphics::IsInsideBeginEnd() { return m_field; }
