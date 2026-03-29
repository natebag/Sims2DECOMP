/* EIStaticSubModel::GetTypeName(void) const - 0x8022F7E4 (12 bytes) */
// TU: e_istaticsubmodel

extern char EIStaticSubModel_typeInfo_name;

struct EIStaticSubModel {
    const char* GetTypeName() const;
};

const char* EIStaticSubModel::GetTypeName() const {
    return &EIStaticSubModel_typeInfo_name;
}
