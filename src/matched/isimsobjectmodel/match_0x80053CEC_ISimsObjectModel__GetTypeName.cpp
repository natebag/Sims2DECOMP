// 0x80053CEC ISimsObjectModel::GetTypeName (12B) const

extern char* g_sObjTypeName[3];

struct ISOM_GTN {
    const char* GetTypeName() const;
};

const char* ISOM_GTN::GetTypeName() const {
    return g_sObjTypeName[0];
}
