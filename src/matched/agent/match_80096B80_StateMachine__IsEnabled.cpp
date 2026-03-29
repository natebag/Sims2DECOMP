struct SM { char p[0x94]; int m_en; int IsEnabled(); };
int SM::IsEnabled() { return m_en; }
