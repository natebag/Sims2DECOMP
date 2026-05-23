// 0x802F2340 EGraphics::IsFirstPassRenderOnly(void) (8 B)
struct EGraphics { char _pad[0x31c]; unsigned m_field; unsigned IsFirstPassRenderOnly(); };
unsigned EGraphics::IsFirstPassRenderOnly() { return m_field; }
