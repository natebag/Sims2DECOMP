// 0x80030730 EIFenceWall::GetTypeKey(void) (12 B)
struct EATypeInfo { char _pad[0x0C]; const char* m_name; unsigned m_key; unsigned short m_version; unsigned short m_readVersion; };
extern EATypeInfo g_EIFenceWallTypeInfo;
struct EIFenceWall { unsigned GetTypeKey(); };
unsigned EIFenceWall::GetTypeKey() { return g_EIFenceWallTypeInfo.m_key; }
