// 0x802380F4 ERLevel::GetTypeInfo (12B) const
struct TypeInfo_ERLevel { char data[256]; };
extern TypeInfo_ERLevel g_ERLevel_TypeInfo[3];
struct ERLevel_GTI { TypeInfo_ERLevel* GetTypeInfo() const; };
TypeInfo_ERLevel* ERLevel_GTI::GetTypeInfo() const { return &g_ERLevel_TypeInfo[0]; }
