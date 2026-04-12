// 0x8022F7F0 match_8022F7F0_EIStaticSubModel_GetTypeKey (12b)
// 0x8022F7F0 EIStaticSubModel::GetTypeKey (12b)
// TU: e_istaticsubmodel

struct TypeInfo {
    char pad[0x10];
    unsigned int m_key;
};

extern TypeInfo EIStaticSubModel_typeInfo;

struct EIStaticSubModel {
    unsigned int GetTypeKey() const;
};

unsigned int EIStaticSubModel::GetTypeKey() const {
    return EIStaticSubModel_typeInfo.m_key;
}
