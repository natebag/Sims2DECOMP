// 0x800350FC ESim::GetTypeName(void) (12 B)
struct EATypeInfo { char _pad[0x0C]; const char* m_name; unsigned m_key; unsigned short m_version; unsigned short m_readVersion; };
extern EATypeInfo g_ESimTypeInfo;
struct ESim { const char* GetTypeName(); };
const char* ESim::GetTypeName() { return g_ESimTypeInfo.m_name; }
