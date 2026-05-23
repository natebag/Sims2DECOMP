// 0x80325588 EQuickdataManager::GetCurrentLanguage(void) (8 B)
struct EQuickdataManager { char _pad[0xd20]; unsigned m_field; unsigned GetCurrentLanguage(); };
unsigned EQuickdataManager::GetCurrentLanguage() { return m_field; }
