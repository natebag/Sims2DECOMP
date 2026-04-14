// 0x803C1420 EStorable::GetTypeInfo (12B) const
struct TypeInfo_EStorable { char data[256]; };
extern TypeInfo_EStorable g_EStorable_TypeInfo[3];
struct EStorable_GTI { TypeInfo_EStorable* GetTypeInfo() const; };
TypeInfo_EStorable* EStorable_GTI::GetTypeInfo() const { return &g_EStorable_TypeInfo[0]; }
