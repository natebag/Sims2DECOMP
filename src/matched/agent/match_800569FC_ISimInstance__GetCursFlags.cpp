struct ISI { char p[0x32C]; int m_flags; int GetCursFlags(); };
int ISI::GetCursFlags() { return m_flags; }
