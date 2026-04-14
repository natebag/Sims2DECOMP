// 0x802293A0 EInstance::GetTypeInfo (12B) const
struct TypeInfo_EInstance { char data[256]; };
extern TypeInfo_EInstance g_EInstance_TypeInfo[3];
struct EInstance_GTI { TypeInfo_EInstance* GetTypeInfo() const; };
TypeInfo_EInstance* EInstance_GTI::GetTypeInfo() const { return &g_EInstance_TypeInfo[0]; }
