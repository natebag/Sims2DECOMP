// 0x8003073C EIFenceWall::GetTypeVersion(void) (12 B)
struct EATypeInfo { char _pad[0x0C]; const char* m_name; unsigned m_key; unsigned short m_version; unsigned short m_readVersion; };
extern EATypeInfo g_EIFenceWallTypeInfo;
struct EIFenceWall { unsigned short GetTypeVersion(); };
unsigned short EIFenceWall::GetTypeVersion() { return g_EIFenceWallTypeInfo.m_version; }
