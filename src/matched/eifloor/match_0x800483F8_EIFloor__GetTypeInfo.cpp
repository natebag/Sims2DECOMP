// 0x800483F8 EIFloor::GetTypeInfo (12B) const
struct TypeInfo_EIFloor { char data[256]; };
extern TypeInfo_EIFloor g_EIFloor_TypeInfo[3];
struct EIFloor_GTI { TypeInfo_EIFloor* GetTypeInfo() const; };
TypeInfo_EIFloor* EIFloor_GTI::GetTypeInfo() const { return &g_EIFloor_TypeInfo[0]; }
