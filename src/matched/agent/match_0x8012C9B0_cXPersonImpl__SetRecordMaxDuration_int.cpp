// 0x8012C9B0 cXPersonImpl::SetRecordMaxDuration(int) (8 B)
struct cXPersonImpl { char _pad[0x438]; unsigned m_recordMaxDuration; void SetRecordMaxDuration(int); };
void cXPersonImpl::SetRecordMaxDuration(int val) { m_recordMaxDuration = val; }
