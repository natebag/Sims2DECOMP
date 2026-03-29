/* ISimsMultiTileObjectModel::GetTypeKey(void) const - 0x80054104 (12 bytes) */
// TU: iobject

extern unsigned int ISimsMultiTileObjectModel_typeInfo_key;

struct ISimsMultiTileObjectModel {
    unsigned int GetTypeKey() const;
};

unsigned int ISimsMultiTileObjectModel::GetTypeKey() const {
    return ISimsMultiTileObjectModel_typeInfo_key;
}
