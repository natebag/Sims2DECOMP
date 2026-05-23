// 0x802F2350 EGraphics::IsEnableFrameEffects(void) (8 B)
struct EGraphics { char _pad[0x320]; unsigned m_field; unsigned IsEnableFrameEffects(); };
unsigned EGraphics::IsEnableFrameEffects() { return m_field; }
