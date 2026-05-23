// 0x8012C9D0 cXPersonImpl::GetRecordSkill(void) (8 B)
struct cXPersonImpl { char _pad[0x448]; unsigned m_recordSkill; unsigned GetRecordSkill(); };
unsigned cXPersonImpl::GetRecordSkill() { return m_recordSkill; }
