// 0x80048410 EIFloor::GetTypeKey(void) (12 B)
struct EATypeInfo { char _pad[0x0C]; const char* m_name; unsigned m_key; unsigned short m_version; unsigned short m_readVersion; };
extern EATypeInfo g_EIFloorTypeInfo;
struct EIFloor { unsigned GetTypeKey(); };
unsigned EIFloor::GetTypeKey() { return g_EIFloorTypeInfo.m_key; }
