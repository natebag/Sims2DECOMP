/* ISimsMultiTileObjectModel::GetTypeName(void) const - 0x800540F8 (12 bytes) */
// TU: iobject

extern char ISimsMultiTileObjectModel_typeInfo_name;

struct ISimsMultiTileObjectModel {
    const char* GetTypeName() const;
};

const char* ISimsMultiTileObjectModel::GetTypeName() const {
    return &ISimsMultiTileObjectModel_typeInfo_name;
}
