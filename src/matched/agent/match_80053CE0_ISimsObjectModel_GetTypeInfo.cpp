/* ISimsObjectModel::GetTypeInfo(void) const - 0x80053CE0 (12 bytes) */
// TU: iobject

struct TypeInfo;

extern TypeInfo ISimsObjectModel_typeInfo;

struct ISimsObjectModel {
    const TypeInfo* GetTypeInfo() const;
};

const TypeInfo* ISimsObjectModel::GetTypeInfo() const {
    return &ISimsObjectModel_typeInfo;
}
