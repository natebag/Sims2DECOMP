// 0x8003056C EIWallPart::GetTypeName(void) (12 B)
struct EATypeInfo { char _pad[0x0C]; const char* m_name; unsigned m_key; unsigned short m_version; unsigned short m_readVersion; };
extern EATypeInfo g_EIWallPartTypeInfo;
struct EIWallPart { const char* GetTypeName(); };
const char* EIWallPart::GetTypeName() { return g_EIWallPartTypeInfo.m_name; }
