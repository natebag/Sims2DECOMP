// 0x802B9190 AptScriptFunctionByteCodeBlock::GetByteCodeBase(void) (8 B)
struct AptScriptFunctionByteCodeBlock { char _pad[0x34]; unsigned m_field; unsigned GetByteCodeBase(); };
unsigned AptScriptFunctionByteCodeBlock::GetByteCodeBase() { return m_field; }
