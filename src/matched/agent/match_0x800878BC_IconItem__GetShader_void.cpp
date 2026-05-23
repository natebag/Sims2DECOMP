// 0x800878BC IconItem::GetShader(void) (8 B)
struct IconItem { char _pad[0x30]; unsigned m_shader; unsigned GetShader(); };
unsigned IconItem::GetShader() { return m_shader; }
