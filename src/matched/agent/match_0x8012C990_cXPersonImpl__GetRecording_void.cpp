// 0x8012C990 cXPersonImpl::GetRecording(void) (8 B)
struct cXPersonImpl { char _pad[0x430]; unsigned m_recording; unsigned GetRecording(); };
unsigned cXPersonImpl::GetRecording() { return m_recording; }
