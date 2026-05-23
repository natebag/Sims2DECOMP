// 0x80048404 EIFloor::GetTypeName(void) (12 B)
struct EATypeInfo { char _pad[0x0C]; const char* m_name; unsigned m_key; unsigned short m_version; unsigned short m_readVersion; };
extern EATypeInfo g_EIFloorTypeInfo;
struct EIFloor { const char* GetTypeName(); };
const char* EIFloor::GetTypeName() { return g_EIFloorTypeInfo.m_name; }
