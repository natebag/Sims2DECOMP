// 0x8012C7E4 cXPersonImpl::GetDestList(void) (8 B)
struct cXPersonImpl { char _pad[1016]; unsigned m_destList[1]; unsigned* GetDestList(); };
unsigned* cXPersonImpl::GetDestList() { return m_destList; }
