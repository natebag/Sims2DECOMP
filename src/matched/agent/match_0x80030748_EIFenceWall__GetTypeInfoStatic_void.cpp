// 0x80030748 EIFenceWall::GetTypeInfoStatic(void) (12 B)
struct EATypeInfo { char _pad[0x0C]; const char* m_name; unsigned m_key; unsigned short m_version; unsigned short m_readVersion; };
extern EATypeInfo g_EIFenceWallTypeInfo;
struct EIFenceWall { static EATypeInfo* GetTypeInfoStatic(); };
EATypeInfo* EIFenceWall::GetTypeInfoStatic() { return &g_EIFenceWallTypeInfo; }
