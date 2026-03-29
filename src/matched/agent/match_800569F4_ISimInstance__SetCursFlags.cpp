struct ISI { char p[0x32C]; int m_flags; void SetCursFlags(int v); };
void ISI::SetCursFlags(int v) { m_flags = v; }
