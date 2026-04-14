// 0x80313D1C ERFlash::GetTypeInfo (12B) const
struct TypeInfo_ERFlash { char data[256]; };
extern TypeInfo_ERFlash g_ERFlash_TypeInfo[3];
struct ERFlash_GTI { TypeInfo_ERFlash* GetTypeInfo() const; };
TypeInfo_ERFlash* ERFlash_GTI::GetTypeInfo() const { return &g_ERFlash_TypeInfo[0]; }
