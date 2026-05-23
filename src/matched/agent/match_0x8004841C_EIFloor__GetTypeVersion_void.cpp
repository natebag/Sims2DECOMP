// 0x8004841C EIFloor::GetTypeVersion(void) (12 B)
struct EATypeInfo { char _pad[0x0C]; const char* m_name; unsigned m_key; unsigned short m_version; unsigned short m_readVersion; };
extern EATypeInfo g_EIFloorTypeInfo;
struct EIFloor { unsigned short GetTypeVersion(); };
unsigned short EIFloor::GetTypeVersion() { return g_EIFloorTypeInfo.m_version; }
