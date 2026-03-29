/* ISimsMultiTileObjectModel::GetReadVersion(void) - 0x80054128 (12 bytes) */
// TU: iobject

extern unsigned int ISimsMultiTileObjectModel_readVersion;

struct ISimsMultiTileObjectModel {
    static unsigned int GetReadVersion();
};

unsigned int ISimsMultiTileObjectModel::GetReadVersion() {
    return ISimsMultiTileObjectModel_readVersion;
}
