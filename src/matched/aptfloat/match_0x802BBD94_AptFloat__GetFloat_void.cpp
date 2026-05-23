// 0x802BBD94 AptFloat::GetFloat(void) (8 B)
struct AptFloat { char _pad[0xc]; float m_field; float GetFloat(); };
float AptFloat::GetFloat() { return m_field; }
