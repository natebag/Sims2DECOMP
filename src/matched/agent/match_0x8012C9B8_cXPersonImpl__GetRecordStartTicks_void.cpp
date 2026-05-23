// 0x8012C9B8 cXPersonImpl::GetRecordStartTicks(void) (8 B)
struct cXPersonImpl { char _pad[0x440]; unsigned m_recordStartTicks; unsigned GetRecordStartTicks(); };
unsigned cXPersonImpl::GetRecordStartTicks() { return m_recordStartTicks; }
