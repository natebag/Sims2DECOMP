struct SM { char p[0x90]; int m_ret; };
struct SMS { char p[8]; SM* m_owner; void OwnerResetReturnVal(); };
void SMS::OwnerResetReturnVal() { m_owner->m_ret = 0; }
