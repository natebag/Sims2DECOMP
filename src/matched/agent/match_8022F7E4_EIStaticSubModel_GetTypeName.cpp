// 0x8022F7E4 match_8022F7E4_EIStaticSubModel_GetTypeName (12b)
// 0x8022F7E4 EIStaticSubModel::GetTypeName (12b)
// TU: e_istaticsubmodel

struct TypeInfo {
    char pad[0x0C];
    const char* m_name;
};

extern TypeInfo EIStaticSubModel_typeInfo;

struct EIStaticSubModel {
    const char* GetTypeName() const;
};

const char* EIStaticSubModel::GetTypeName() const {
    return EIStaticSubModel_typeInfo.m_name;
}
