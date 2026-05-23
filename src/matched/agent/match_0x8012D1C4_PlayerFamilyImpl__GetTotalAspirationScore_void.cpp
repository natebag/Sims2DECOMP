// 0x8012D1C4 PlayerFamilyImpl::GetTotalAspirationScore(void) (8 B)
struct PlayerFamilyImpl { char _pad[0xd60]; unsigned m_totalAspirationScore; unsigned GetTotalAspirationScore(); };
unsigned PlayerFamilyImpl::GetTotalAspirationScore() { return m_totalAspirationScore; }
