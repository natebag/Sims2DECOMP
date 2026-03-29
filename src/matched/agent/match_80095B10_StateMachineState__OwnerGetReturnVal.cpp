struct SM { char p[0x90]; int m_ret; };
struct SMS { char p[8]; SM* m_owner; int OwnerGetReturnVal(); };
int SMS::OwnerGetReturnVal() { return m_owner->m_ret; }
