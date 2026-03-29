/* EIStaticSubModel::GetTypeInfo(void) const - 0x8022F7D8 (12 bytes) */
// TU: e_istaticsubmodel

struct TypeInfo;

extern TypeInfo EIStaticSubModel_typeInfo;

struct EIStaticSubModel {
    const TypeInfo* GetTypeInfo() const;
};

const TypeInfo* EIStaticSubModel::GetTypeInfo() const {
    return &EIStaticSubModel_typeInfo;
}
