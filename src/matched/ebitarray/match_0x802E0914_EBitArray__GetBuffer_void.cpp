// 0x802E0914 EBitArray::GetBuffer(void) (8 B)
struct EBitArray { unsigned m_field; unsigned GetBuffer(); };
unsigned EBitArray::GetBuffer() { return m_field; }
