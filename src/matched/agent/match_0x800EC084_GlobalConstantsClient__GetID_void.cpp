// 0x800EC084 GlobalConstantsClient::GetID(void) (8 B)
struct GlobalConstantsClient { char _pad[0x4]; short m_id; int GetID(); };
int GlobalConstantsClient::GetID() { return m_id; }
