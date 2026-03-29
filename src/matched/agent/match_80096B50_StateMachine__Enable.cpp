struct SM { char p[0x94]; int m_en; void Enable(); };
void SM::Enable() { m_en = 1; }
