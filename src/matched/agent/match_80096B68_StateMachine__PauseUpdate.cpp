struct SM { char p[0x24]; int m_pau; void PauseUpdate(); };
void SM::PauseUpdate() { m_pau = 1; }
