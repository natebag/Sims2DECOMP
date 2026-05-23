// 0x8012C9A8 cXPersonImpl::GetRecordMaxDuration(void) (8 B)
struct cXPersonImpl { char _pad[0x438]; unsigned m_recordMaxDuration; unsigned GetRecordMaxDuration(); };
unsigned cXPersonImpl::GetRecordMaxDuration() { return m_recordMaxDuration; }
