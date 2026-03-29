/* ISimsWallObjectModel::GetTypeKey(void) const - 0x80053F70 (12 bytes) */
// TU: iobject

extern unsigned int ISimsWallObjectModel_typeInfo_key;

struct ISimsWallObjectModel {
    unsigned int GetTypeKey() const;
};

unsigned int ISimsWallObjectModel::GetTypeKey() const {
    return ISimsWallObjectModel_typeInfo_key;
}
