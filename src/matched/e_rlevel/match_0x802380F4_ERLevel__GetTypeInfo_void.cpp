// 0x802380F4 ERLevel::GetTypeInfo(void) (12 B)
// lis 3,-32688; addi 3,3,-13080 => return &ERLevel::m_typeInfo (0x804FCCE8)
struct TypeInfo_ERLevel { char data[40]; };
extern TypeInfo_ERLevel g_ERLevel_TypeInfo[3];
struct ERLevel_GTI { TypeInfo_ERLevel* GetTypeInfo() const; };
TypeInfo_ERLevel* ERLevel_GTI::GetTypeInfo() const { return &g_ERLevel_TypeInfo[0]; }
