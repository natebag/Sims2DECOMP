// 0x8003512C ESim::GetReadVersion(void) (12 B)
struct EATypeInfo { char _pad[0x0C]; const char* m_name; unsigned m_key; unsigned short m_version; unsigned short m_readVersion; };
extern EATypeInfo g_ESimTypeInfo;
struct ESim { unsigned short GetReadVersion(); };
unsigned short ESim::GetReadVersion() { return g_ESimTypeInfo.m_readVersion; }
