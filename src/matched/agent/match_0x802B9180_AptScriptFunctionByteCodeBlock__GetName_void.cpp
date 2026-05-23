// 0x802B9180 AptScriptFunctionByteCodeBlock::GetName(void) (8 B)
struct AptScriptFunctionByteCodeBlock { char _pad[0x3c]; unsigned m_field; unsigned GetName(); };
unsigned AptScriptFunctionByteCodeBlock::GetName() { return m_field; }
