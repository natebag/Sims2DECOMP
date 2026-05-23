// 0x8012CA4C cXPersonImpl::IsFirstPlayerInSocialMode(void) (8 B)
struct cXPersonImpl { char _pad[0x544]; unsigned m_firstPlayerInSocialMode; unsigned IsFirstPlayerInSocialMode(); };
unsigned cXPersonImpl::IsFirstPlayerInSocialMode() { return m_firstPlayerInSocialMode; }
