// 0x80327ECC EResourceManager::IsInitialized(void) (8 B)
struct EResourceManager { char _pad[0x48]; unsigned m_field; unsigned IsInitialized(); };
unsigned EResourceManager::IsInitialized() { return m_field; }
