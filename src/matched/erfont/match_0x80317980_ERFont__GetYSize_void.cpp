// 0x80317980 ERFont::GetYSize(void) (8 B)
struct ERFont { char _pad[0x4c]; float m_field; float GetYSize(); };
float ERFont::GetYSize() { return m_field; }
