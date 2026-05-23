// 0x800900A0 ELiveMode::SetDontDraw(bool) (8 B)
struct ELiveMode { char _pad[0x34]; unsigned m_dontDraw; void SetDontDraw(bool); };
void ELiveMode::SetDontDraw(bool val) { m_dontDraw = val; }
