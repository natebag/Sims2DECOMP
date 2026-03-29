/* ISimsObjectModel::GetReadVersion(void) - 0x80053D1C (12 bytes) */
// TU: iobject

extern unsigned int ISimsObjectModel_readVersion;

struct ISimsObjectModel {
    static unsigned int GetReadVersion();
};

unsigned int ISimsObjectModel::GetReadVersion() {
    return ISimsObjectModel_readVersion;
}
