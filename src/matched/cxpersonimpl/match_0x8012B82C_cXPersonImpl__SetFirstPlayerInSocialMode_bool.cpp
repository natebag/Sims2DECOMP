// 0x8012B82C cXPersonImpl::SetFirstPlayerInSocialMode(bool) (8 B)
struct cXPersonImpl { char _pad[0x544]; unsigned m_firstPlayerInSocialMode; void SetFirstPlayerInSocialMode(bool); };
void cXPersonImpl::SetFirstPlayerInSocialMode(bool val) { m_firstPlayerInSocialMode = val; }
