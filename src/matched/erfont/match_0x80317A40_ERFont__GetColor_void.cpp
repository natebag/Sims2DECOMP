// 0x80317A40 ERFont::GetColor(void) (8 B)
struct ERFont { char _pad[88]; unsigned m_arr[1]; unsigned* GetColor(); };
unsigned* ERFont::GetColor() { return m_arr; }
