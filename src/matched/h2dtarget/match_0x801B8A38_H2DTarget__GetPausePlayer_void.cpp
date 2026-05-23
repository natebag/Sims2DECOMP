// 0x801B8A38 H2DTarget::GetPausePlayer(void) (8 B)
struct H2DTarget { char _pad[0xd0]; unsigned m_field; unsigned GetPausePlayer(); };
unsigned H2DTarget::GetPausePlayer() { return m_field; }
