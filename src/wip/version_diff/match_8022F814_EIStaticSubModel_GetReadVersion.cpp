/* EIStaticSubModel::GetReadVersion(void) - 0x8022F814 (12 bytes) */
// TU: e_istaticsubmodel

extern unsigned int EIStaticSubModel_readVersion;

struct EIStaticSubModel {
    static unsigned int GetReadVersion();
};

unsigned int EIStaticSubModel::GetReadVersion() {
    return EIStaticSubModel_readVersion;
}
