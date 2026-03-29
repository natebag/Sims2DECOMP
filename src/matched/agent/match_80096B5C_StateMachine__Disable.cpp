struct SM { char p[0x94]; int m_en; void Disable(); };
void SM::Disable() { m_en = 0; }
