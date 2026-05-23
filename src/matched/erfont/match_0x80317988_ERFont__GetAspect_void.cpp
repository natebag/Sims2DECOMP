// 0x80317988 ERFont::GetAspect(void) (8 B)
struct ERFont { char _pad[0x50]; float m_field; float GetAspect(); };
float ERFont::GetAspect() { return m_field; }
