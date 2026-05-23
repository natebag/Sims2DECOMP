// 0x803293F0 FreeResourceManager::GetUnreferencedResourceCount(void) (8 B)
struct FreeResourceManager { char _pad[0xca0]; unsigned m_field; unsigned GetUnreferencedResourceCount(); };
unsigned FreeResourceManager::GetUnreferencedResourceCount() { return m_field; }
