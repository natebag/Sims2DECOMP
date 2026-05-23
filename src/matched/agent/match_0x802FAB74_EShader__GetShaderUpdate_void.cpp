// 0x802FAB74 EShader::GetShaderUpdate(void) (8 B)
struct EShader { char _pad[0xe8]; unsigned m_field; unsigned GetShaderUpdate(); };
unsigned EShader::GetShaderUpdate() { return m_field; }
