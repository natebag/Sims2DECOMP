// 0x8012CA44 cXPersonImpl::IsSecondPlayerInSocialMode(void) (8 B)
struct cXPersonImpl { char _pad[0x548]; unsigned m_secondPlayerInSocialMode; unsigned IsSecondPlayerInSocialMode(); };
unsigned cXPersonImpl::IsSecondPlayerInSocialMode() { return m_secondPlayerInSocialMode; }
