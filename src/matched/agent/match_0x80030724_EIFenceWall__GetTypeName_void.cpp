// 0x80030724 EIFenceWall::GetTypeName(void) (12 B)
struct EATypeInfo { char _pad[0x0C]; const char* m_name; unsigned m_key; unsigned short m_version; unsigned short m_readVersion; };
extern EATypeInfo g_EIFenceWallTypeInfo;
struct EIFenceWall { const char* GetTypeName(); };
const char* EIFenceWall::GetTypeName() { return g_EIFenceWallTypeInfo.m_name; }
