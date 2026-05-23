// 0x80036E80 ESpriteRender::GetMarkedAsNew(void) (8 B)
struct ESpriteRender { char _pad[4]; unsigned m_markedAsNew; unsigned GetMarkedAsNew(); };
unsigned ESpriteRender::GetMarkedAsNew() { return m_markedAsNew; }
