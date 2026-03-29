struct SM { char p[0x24]; int m_pau; void UnpauseUpdate(); };
void SM::UnpauseUpdate() { m_pau = 0; }
