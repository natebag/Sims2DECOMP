struct ASP { char p[0x14]; int m_vol; int SetVolume(int v); };
int ASP::SetVolume(int v) { m_vol = v; return 1; }
