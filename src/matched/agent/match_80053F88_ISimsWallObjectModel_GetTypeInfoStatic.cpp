/* ISimsWallObjectModel::GetTypeInfoStatic(void) - 0x80053F88 (12 bytes) */
// TU: iobject

struct TypeInfo;

extern TypeInfo ISimsWallObjectModel_typeInfo;

struct ISimsWallObjectModel {
    static const TypeInfo* GetTypeInfoStatic();
};

const TypeInfo* ISimsWallObjectModel::GetTypeInfoStatic() {
    return &ISimsWallObjectModel_typeInfo;
}
