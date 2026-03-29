/* ISimsObjectModel::GetTypeKey(void) const - 0x80053CF8 (12 bytes) */
// TU: iobject

extern unsigned int ISimsObjectModel_typeInfo_key;

struct ISimsObjectModel {
    unsigned int GetTypeKey() const;
};

unsigned int ISimsObjectModel::GetTypeKey() const {
    return ISimsObjectModel_typeInfo_key;
}
