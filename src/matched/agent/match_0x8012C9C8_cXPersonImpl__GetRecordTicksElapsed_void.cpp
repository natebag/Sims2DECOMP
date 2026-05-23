// 0x8012C9C8 cXPersonImpl::GetRecordTicksElapsed(void) (8 B)
struct cXPersonImpl { char _pad[0x444]; unsigned m_recordTicksElapsed; unsigned GetRecordTicksElapsed(); };
unsigned cXPersonImpl::GetRecordTicksElapsed() { return m_recordTicksElapsed; }
