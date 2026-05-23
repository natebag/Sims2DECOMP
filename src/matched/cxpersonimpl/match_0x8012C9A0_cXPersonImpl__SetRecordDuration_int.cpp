// 0x8012C9A0 cXPersonImpl::SetRecordDuration(int) (8 B)
struct cXPersonImpl { char _pad[0x434]; unsigned m_recordDuration; void SetRecordDuration(int); };
void cXPersonImpl::SetRecordDuration(int val) { m_recordDuration = val; }
