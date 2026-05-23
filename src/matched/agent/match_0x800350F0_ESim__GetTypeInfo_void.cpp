// 0x800350F0 ESim::GetTypeInfo(void) (12 B)
struct EATypeInfo { char _pad[0x0C]; const char* m_name; unsigned m_key; unsigned short m_version; unsigned short m_readVersion; };
extern EATypeInfo g_ESimTypeInfo;
struct ESim { EATypeInfo* GetTypeInfo(); };
EATypeInfo* ESim::GetTypeInfo() { return &g_ESimTypeInfo; }
