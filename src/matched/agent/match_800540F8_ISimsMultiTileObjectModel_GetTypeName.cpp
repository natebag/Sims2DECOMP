/* ISimsMultiTileObjectModel::GetTypeName(void) const - 0x800540F8 (12 bytes) */
// TU: iobject

typedef struct TypeInfo TypeInfo;

extern TypeInfo ISimsMultiTileObjectModel_typeInfo;

struct ISimsMultiTileObjectModel {
    const char* GetTypeName() const;
};

const char* ISimsMultiTileObjectModel::GetTypeName() const {
    return *(const char**)((char*)&ISimsMultiTileObjectModel_typeInfo + 12);
}
