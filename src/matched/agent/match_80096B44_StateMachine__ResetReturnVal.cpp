struct SM { char p[0x90]; int m_ret; void ResetReturnVal(); };
void SM::ResetReturnVal() { m_ret = 0; }
