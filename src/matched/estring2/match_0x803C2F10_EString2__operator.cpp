// 0x803C2F10 EString2::operator(void) (8 B)
struct EString2 { unsigned m_field; unsigned operator_deref(); };
unsigned EString2::operator_deref() { return m_field; }
