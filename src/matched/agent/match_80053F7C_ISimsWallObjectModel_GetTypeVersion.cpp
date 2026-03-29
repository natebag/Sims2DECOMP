/* ISimsWallObjectModel::GetTypeVersion(void) const - 0x80053F7C (12 bytes) */
// TU: iobject

extern unsigned int ISimsWallObjectModel_typeInfo_version;

struct ISimsWallObjectModel {
    unsigned int GetTypeVersion() const;
};

unsigned int ISimsWallObjectModel::GetTypeVersion() const {
    return ISimsWallObjectModel_typeInfo_version;
}
