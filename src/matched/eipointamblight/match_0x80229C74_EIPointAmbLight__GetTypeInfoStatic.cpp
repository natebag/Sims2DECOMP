// 0x80229C74 EIPointAmbLight::GetTypeInfoStatic (12B)
struct TypeInfo_EIPointAmbLight { char data[256]; };
extern TypeInfo_EIPointAmbLight g_EIPointAmbLight_TypeInfo[3];
TypeInfo_EIPointAmbLight* EIPointAmbLight_GetTypeInfoStatic() { return &g_EIPointAmbLight_TypeInfo[0]; }
