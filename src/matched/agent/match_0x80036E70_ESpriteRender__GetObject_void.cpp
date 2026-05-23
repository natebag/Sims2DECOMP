// 0x80036E70 ESpriteRender::GetObject(void) (8 B)
struct ESpriteRender { char _pad[0x8]; unsigned m_object; unsigned GetObject(); };
unsigned ESpriteRender::GetObject() { return m_object; }
