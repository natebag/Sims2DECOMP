/* ISimsMultiTileObjectModel::GetTypeVersion(void) const - 0x80054110 (12 bytes) */
// TU: iobject

typedef struct TypeInfo TypeInfo;

extern TypeInfo ISimsMultiTileObjectModel_typeInfo;

struct ISimsMultiTileObjectModel {
    short GetTypeVersion() const;
};

short ISimsMultiTileObjectModel::GetTypeVersion() const {
    return *(short*)((char*)&ISimsMultiTileObjectModel_typeInfo + 20);
}
