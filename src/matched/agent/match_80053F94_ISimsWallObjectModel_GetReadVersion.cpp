/* ISimsWallObjectModel::GetReadVersion(void) - 0x80053F94 (12 bytes) */
// TU: iobject

extern unsigned int ISimsWallObjectModel_readVersion;

struct ISimsWallObjectModel {
    static unsigned int GetReadVersion();
};

unsigned int ISimsWallObjectModel::GetReadVersion() {
    return ISimsWallObjectModel_readVersion;
}
