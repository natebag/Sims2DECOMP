// 0x80030578 EIWallPart::GetTypeKey(void) (12 B)
struct EATypeInfo { char _pad[0x0C]; const char* m_name; unsigned m_key; unsigned short m_version; unsigned short m_readVersion; };
extern EATypeInfo g_EIWallPartTypeInfo;
struct EIWallPart { unsigned GetTypeKey(); };
unsigned EIWallPart::GetTypeKey() { return g_EIWallPartTypeInfo.m_key; }
