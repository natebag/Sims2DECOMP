// 0x80238118 ERLevel::GetTypeVersion(void) (12 B)
// lis 9,-32688; lhz 3,-13060(9) => return m_typeInfo.m_typeVersion
struct TypeInfo_ERLevel { char data[20]; unsigned short m_typeVersion; };
extern TypeInfo_ERLevel g_ERLevel_TypeInfo[3];
struct ERLevel_GTV { unsigned short GetTypeVersion() const; };
unsigned short ERLevel_GTV::GetTypeVersion() const { return g_ERLevel_TypeInfo[0].m_typeVersion; }
