// 0x8023810C ERLevel::GetTypeKey(void) (12 B)
// lis 9,-32688; lwz 3,-13064(9) => return m_typeInfo.m_typeKey
struct TypeInfo_ERLevel { char data[16]; unsigned m_typeKey; };
extern TypeInfo_ERLevel g_ERLevel_TypeInfo[3];
struct ERLevel_GTK { unsigned GetTypeKey() const; };
unsigned ERLevel_GTK::GetTypeKey() const { return g_ERLevel_TypeInfo[0].m_typeKey; }
