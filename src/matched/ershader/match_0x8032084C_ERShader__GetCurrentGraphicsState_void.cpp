// 0x8032084C ERShader::GetCurrentGraphicsState(void) (8 B)
struct ERShader { char _pad[0x50]; unsigned char m_field; unsigned char GetCurrentGraphicsState(); };
unsigned char ERShader::GetCurrentGraphicsState() { return m_field; }
