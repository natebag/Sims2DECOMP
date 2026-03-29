/* ISimsObjectModel::GetTypeVersion(void) const - 0x80053D04 (12 bytes) */
// TU: iobject

extern unsigned int ISimsObjectModel_typeInfo_version;

struct ISimsObjectModel {
    unsigned int GetTypeVersion() const;
};

unsigned int ISimsObjectModel::GetTypeVersion() const {
    return ISimsObjectModel_typeInfo_version;
}
