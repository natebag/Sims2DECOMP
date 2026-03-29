struct SM { char p[0x20]; void* m_mgr; void* GetManager() const; };
void* SM::GetManager() const { return m_mgr; }
