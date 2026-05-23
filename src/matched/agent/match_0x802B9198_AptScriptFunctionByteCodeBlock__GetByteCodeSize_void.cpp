// 0x802B9198 AptScriptFunctionByteCodeBlock::GetByteCodeSize(void) (8 B)
struct AptScriptFunctionByteCodeBlock { char _pad[0x38]; unsigned m_field; unsigned GetByteCodeSize(); };
unsigned AptScriptFunctionByteCodeBlock::GetByteCodeSize() { return m_field; }
