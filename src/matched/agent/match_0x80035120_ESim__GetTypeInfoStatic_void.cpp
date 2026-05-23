// 0x80035120 ESim::GetTypeInfoStatic(void) (12 B)
struct EATypeInfo { char _pad[0x0C]; const char* m_name; unsigned m_key; unsigned short m_version; unsigned short m_readVersion; };
extern EATypeInfo g_ESimTypeInfo;
struct ESim { static EATypeInfo* GetTypeInfoStatic(); };
EATypeInfo* ESim::GetTypeInfoStatic() { return &g_ESimTypeInfo; }
