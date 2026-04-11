/* ISimsMultiTileObjectModel::GetTypeKey(void) const - 0x80054104 (12 bytes) */
// TU: iobject

typedef struct TypeInfo TypeInfo;

extern TypeInfo ISimsMultiTileObjectModel_typeInfo;

struct ISimsMultiTileObjectModel {
    const char* GetTypeKey() const;
};

const char* ISimsMultiTileObjectModel::GetTypeKey() const {
    return *(const char**)((char*)&ISimsMultiTileObjectModel_typeInfo + 16);
}
