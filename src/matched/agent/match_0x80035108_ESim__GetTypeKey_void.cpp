// 0x80035108 ESim::GetTypeKey(void) (12 B)
struct EATypeInfo { char _pad[0x0C]; const char* m_name; unsigned m_key; unsigned short m_version; unsigned short m_readVersion; };
extern EATypeInfo g_ESimTypeInfo;
struct ESim { unsigned GetTypeKey(); };
unsigned ESim::GetTypeKey() { return g_ESimTypeInfo.m_key; }
