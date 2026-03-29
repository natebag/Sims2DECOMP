/* ISimsMultiTileObjectModel::GetTypeInfoStatic(void) - 0x8005411C (12 bytes) */
// TU: iobject

struct TypeInfo;

extern TypeInfo ISimsMultiTileObjectModel_typeInfo;

struct ISimsMultiTileObjectModel {
    static const TypeInfo* GetTypeInfoStatic();
};

const TypeInfo* ISimsMultiTileObjectModel::GetTypeInfoStatic() {
    return &ISimsMultiTileObjectModel_typeInfo;
}
