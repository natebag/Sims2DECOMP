// 0x800542B0 ISimsCounterTopObject::GetTypeInfoStatic (12B)

struct TypeInfo_ISimsCounterTopObject { char data[256]; };
extern TypeInfo_ISimsCounterTopObject g_ISimsCounterTopObject_TypeInfo[3];

TypeInfo_ISimsCounterTopObject* ISimsCounterTopObject_GetTypeInfoStatic() {
    return &g_ISimsCounterTopObject_TypeInfo[0];
}
