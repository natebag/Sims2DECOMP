// 0x8012C9C0 cXPersonImpl::GetRecordCurTicks(void) (8 B)
struct cXPersonImpl { char _pad[0x43c]; unsigned m_recordCurTicks; unsigned GetRecordCurTicks(); };
unsigned cXPersonImpl::GetRecordCurTicks() { return m_recordCurTicks; }
