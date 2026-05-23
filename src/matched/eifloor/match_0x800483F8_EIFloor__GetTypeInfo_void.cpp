// 0x800483F8 EIFloor::GetTypeInfo(void) (12 B)
struct EATypeInfo { char _pad[0x0C]; const char* m_name; unsigned m_key; unsigned short m_version; unsigned short m_readVersion; };
extern EATypeInfo g_EIFloorTypeInfo;
struct EIFloor { EATypeInfo* GetTypeInfo(); };
EATypeInfo* EIFloor::GetTypeInfo() { return &g_EIFloorTypeInfo; }
