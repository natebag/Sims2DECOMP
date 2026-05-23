// 0x8012C978 cXPersonImpl::GetVisibility(void) (8 B)
struct cXPersonImpl { char _pad[0x9c]; short m_visibility; int GetVisibility(); };
int cXPersonImpl::GetVisibility() { return m_visibility; }
