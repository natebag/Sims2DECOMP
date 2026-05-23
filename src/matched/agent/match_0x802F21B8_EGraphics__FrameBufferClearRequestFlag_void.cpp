// 0x802F21B8 EGraphics::FrameBufferClearRequestFlag(void) (8 B)
struct EGraphics { char _pad[0x10]; unsigned m_field; unsigned FrameBufferClearRequestFlag(); };
unsigned EGraphics::FrameBufferClearRequestFlag() { return m_field; }
