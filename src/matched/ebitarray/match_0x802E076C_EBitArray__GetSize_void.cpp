// 0x802E076C EBitArray::GetSize(void) (8 B)
struct EBitArray { char _pad[0x4]; unsigned m_field; unsigned GetSize(); };
unsigned EBitArray::GetSize() { return m_field; }
