// 0x80053D10 ISimsObjectModel::GetTypeInfoStatic (12B)

struct TypeInfo { char data[256]; };
extern TypeInfo g_sObjTypeInfo[3];

TypeInfo* ISimsObjectModel_GetTypeInfoStatic() {
    return &g_sObjTypeInfo[0];
}
