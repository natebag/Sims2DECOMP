// 0x80317848 ERFont::GetTypeInfo (12B) const
struct TypeInfo_ERFont { char data[256]; };
extern TypeInfo_ERFont g_ERFont_TypeInfo[3];
struct ERFont_GTI { TypeInfo_ERFont* GetTypeInfo() const; };
TypeInfo_ERFont* ERFont_GTI::GetTypeInfo() const { return &g_ERFont_TypeInfo[0]; }
