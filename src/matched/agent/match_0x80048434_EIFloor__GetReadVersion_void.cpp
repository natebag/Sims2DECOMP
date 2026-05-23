// 0x80048434 EIFloor::GetReadVersion(void) (12 B)
struct EATypeInfo { char _pad[0x0C]; const char* m_name; unsigned m_key; unsigned short m_version; unsigned short m_readVersion; };
extern EATypeInfo g_EIFloorTypeInfo;
struct EIFloor { unsigned short GetReadVersion(); };
unsigned short EIFloor::GetReadVersion() { return g_EIFloorTypeInfo.m_readVersion; }
