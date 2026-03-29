struct ASP { char p[0x14]; int m_vol; int GetVolume(); };
int ASP::GetVolume() { return m_vol; }
