// 0x802FAAEC EShader::GetSurfaceProperties(void) (8 B)
struct EShader { char _pad[0x4]; unsigned m_field; unsigned GetSurfaceProperties(); };
unsigned EShader::GetSurfaceProperties() { return m_field; }
