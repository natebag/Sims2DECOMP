// 0x8012CA54 cXPersonImpl::IsWaitingForSocialMode(void) (8 B)
struct cXPersonImpl { char _pad[0x54c]; unsigned m_waitingForSocialMode; unsigned IsWaitingForSocialMode(); };
unsigned cXPersonImpl::IsWaitingForSocialMode() { return m_waitingForSocialMode; }
