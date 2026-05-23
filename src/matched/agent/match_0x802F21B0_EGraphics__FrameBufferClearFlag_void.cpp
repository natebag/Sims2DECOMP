// 0x802F21B0 EGraphics::FrameBufferClearFlag(void) (8 B)
struct EGraphics { char _pad[0xc]; unsigned m_field; unsigned FrameBufferClearFlag(); };
unsigned EGraphics::FrameBufferClearFlag() { return m_field; }
