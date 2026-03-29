/* ISimsWallObjectModel::GetTypeInfo(void) const - 0x80053F58 (12 bytes) */
// TU: iobject

struct TypeInfo;

extern TypeInfo ISimsWallObjectModel_typeInfo;

struct ISimsWallObjectModel {
    const TypeInfo* GetTypeInfo() const;
};

const TypeInfo* ISimsWallObjectModel::GetTypeInfo() const {
    return &ISimsWallObjectModel_typeInfo;
}
