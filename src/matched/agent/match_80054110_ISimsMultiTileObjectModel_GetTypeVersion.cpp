/* ISimsMultiTileObjectModel::GetTypeVersion(void) const - 0x80054110 (12 bytes) */
// TU: iobject

extern unsigned int ISimsMultiTileObjectModel_typeInfo_version;

struct ISimsMultiTileObjectModel {
    unsigned int GetTypeVersion() const;
};

unsigned int ISimsMultiTileObjectModel::GetTypeVersion() const {
    return ISimsMultiTileObjectModel_typeInfo_version;
}
