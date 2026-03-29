struct SM { char p[0x90]; int m_ret; int GetReturnVal() const; };
int SM::GetReturnVal() const { return m_ret; }
