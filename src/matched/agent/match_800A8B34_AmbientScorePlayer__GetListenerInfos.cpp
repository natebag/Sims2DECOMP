struct ASP { char p[0x20]; int m_data; void* GetListenerInfos(); };
void* ASP::GetListenerInfos() { return &m_data; }
