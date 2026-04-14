// 0x802277FC EIGameInstance::GetTypeInfo (12B) const
struct TypeInfo_EIGameInstance { char data[256]; };
extern TypeInfo_EIGameInstance g_EIGameInstance_TypeInfo[3];
struct EIGameInstance_GTI { TypeInfo_EIGameInstance* GetTypeInfo() const; };
TypeInfo_EIGameInstance* EIGameInstance_GTI::GetTypeInfo() const { return &g_EIGameInstance_TypeInfo[0]; }
