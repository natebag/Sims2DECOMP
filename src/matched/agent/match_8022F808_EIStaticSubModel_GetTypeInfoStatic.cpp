/* EIStaticSubModel::GetTypeInfoStatic(void) - 0x8022F808 (12 bytes) */
// TU: e_istaticsubmodel

struct TypeInfo;

extern TypeInfo EIStaticSubModel_typeInfo;

struct EIStaticSubModel {
    static const TypeInfo* GetTypeInfoStatic();
};

const TypeInfo* EIStaticSubModel::GetTypeInfoStatic() {
    return &EIStaticSubModel_typeInfo;
}
