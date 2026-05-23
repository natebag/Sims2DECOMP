// 0x80048428 EIFloor::GetTypeInfoStatic(void) (12 B)
struct EATypeInfo { char _pad[0x0C]; const char* m_name; unsigned m_key; unsigned short m_version; unsigned short m_readVersion; };
extern EATypeInfo g_EIFloorTypeInfo;
struct EIFloor { static EATypeInfo* GetTypeInfoStatic(); };
EATypeInfo* EIFloor::GetTypeInfoStatic() { return &g_EIFloorTypeInfo; }
