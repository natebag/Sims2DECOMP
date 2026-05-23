// 0x8012C998 cXPersonImpl::GetRecordDuration(void) (8 B)
struct cXPersonImpl { char _pad[0x434]; unsigned m_recordDuration; unsigned GetRecordDuration(); };
unsigned cXPersonImpl::GetRecordDuration() { return m_recordDuration; }
