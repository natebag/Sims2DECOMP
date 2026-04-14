// 0x80054444 IShrubObject::GetTypeInfoStatic (12B)

struct TypeInfo_IShrubObject { char data[256]; };
extern TypeInfo_IShrubObject g_IShrubObject_TypeInfo[3];

TypeInfo_IShrubObject* IShrubObject_GetTypeInfoStatic() {
    return &g_IShrubObject_TypeInfo[0];
}
