// 0x80238130 ERLevel::GetReadVersion(void) (12 B)
// lis 9,-32688; lhz 3,-13058(9) => return m_typeInfo.m_readVersion
struct TypeInfo_ERLevel { char data[22]; unsigned short m_readVersion; };
extern TypeInfo_ERLevel g_ERLevel_TypeInfo[3];
struct ERLevel_GRV { unsigned short GetReadVersion() const; };
unsigned short ERLevel_GRV::GetReadVersion() const { return g_ERLevel_TypeInfo[0].m_readVersion; }
