// 0x800568DC ISimInstance::GetTypeInfoStatic (12B)

struct TypeInfo_ISimInstance { char data[256]; };
extern TypeInfo_ISimInstance g_ISimInstance_TypeInfo[3];

TypeInfo_ISimInstance* ISimInstance_GetTypeInfoStatic() {
    return &g_ISimInstance_TypeInfo[0];
}
