// 0x802D283C EStream::IsStreamingStructure(void) (8 B)
struct EStream { unsigned m_field; unsigned IsStreamingStructure(); };
unsigned EStream::IsStreamingStructure() { return m_field; }
