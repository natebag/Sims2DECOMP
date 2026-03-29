struct SM { char p[0x24]; int m_pau; int IsPausedUpdate(); };
int SM::IsPausedUpdate() { return m_pau; }
