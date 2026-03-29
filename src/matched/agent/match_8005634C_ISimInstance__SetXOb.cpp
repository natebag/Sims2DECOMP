struct ISI { char p[0x328]; int m_xob; void SetXOb(int v); };
void ISI::SetXOb(int v) { m_xob = v; }
