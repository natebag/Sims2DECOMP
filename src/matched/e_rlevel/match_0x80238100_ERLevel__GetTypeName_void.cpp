// 0x80238100 ERLevel::GetTypeName(void) (12 B)
// lis 9,-32688; lwz 3,-13068(9) => return m_typeInfo.m_typeName
struct TypeInfo_ERLevel { char data[12]; char* m_typeName; };
extern TypeInfo_ERLevel g_ERLevel_TypeInfo[3];
struct ERLevel_GTN { const char* GetTypeName() const; };
const char* ERLevel_GTN::GetTypeName() const { return g_ERLevel_TypeInfo[0].m_typeName; }
