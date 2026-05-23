// 0x80312274 EResource::GetResId(void) (8 B)
struct EResource { char _pad[0x8]; unsigned m_field; unsigned GetResId(); };
unsigned EResource::GetResId() { return m_field; }
