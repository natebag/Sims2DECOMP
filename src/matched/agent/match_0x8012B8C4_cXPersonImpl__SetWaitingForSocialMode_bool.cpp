// 0x8012B8C4 cXPersonImpl::SetWaitingForSocialMode(bool) (8 B)
struct cXPersonImpl { char _pad[0x54c]; unsigned m_waitingForSocialMode; void SetWaitingForSocialMode(bool); };
void cXPersonImpl::SetWaitingForSocialMode(bool val) { m_waitingForSocialMode = val; }
