/* ISimsMultiTileObjectModel::GetReadVersion(void) const - 0x80054128 (12 bytes) */
// TU: iobject

typedef struct TypeInfo TypeInfo;

extern TypeInfo ISimsMultiTileObjectModel_typeInfo;

struct ISimsMultiTileObjectModel {
    short GetReadVersion() const;
};

short ISimsMultiTileObjectModel::GetReadVersion() const {
    return *(short*)((char*)&ISimsMultiTileObjectModel_typeInfo + 22);
}
