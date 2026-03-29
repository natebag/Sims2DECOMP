/* ISimsMultiTileObjectModel::GetTypeInfo(void) const - 0x800540EC (12 bytes) */
// TU: iobject

struct TypeInfo;

extern TypeInfo ISimsMultiTileObjectModel_typeInfo;

struct ISimsMultiTileObjectModel {
    const TypeInfo* GetTypeInfo() const;
};

const TypeInfo* ISimsMultiTileObjectModel::GetTypeInfo() const {
    return &ISimsMultiTileObjectModel_typeInfo;
}
