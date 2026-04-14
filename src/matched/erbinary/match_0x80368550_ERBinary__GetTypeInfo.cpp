// 0x80368550 ERBinary::GetTypeInfo (12B) const
struct TypeInfo_ERBinary { char data[256]; };
extern TypeInfo_ERBinary g_ERBinary_TypeInfo[3];
struct ERBinary_GTI { TypeInfo_ERBinary* GetTypeInfo() const; };
TypeInfo_ERBinary* ERBinary_GTI::GetTypeInfo() const { return &g_ERBinary_TypeInfo[0]; }
