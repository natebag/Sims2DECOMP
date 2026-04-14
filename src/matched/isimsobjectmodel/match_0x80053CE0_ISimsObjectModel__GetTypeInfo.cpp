// 0x80053CE0 ISimsObjectModel::GetTypeInfo (12B) const

struct TypeInfo { char data[256]; };
extern TypeInfo g_sObjTypeInfo[3];

struct ISOM_GTI {
    TypeInfo* GetTypeInfo() const;
};

TypeInfo* ISOM_GTI::GetTypeInfo() const {
    return &g_sObjTypeInfo[0];
}
