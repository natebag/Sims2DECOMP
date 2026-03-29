/* EIStaticSubModel::GetTypeVersion(void) const - 0x8022F7FC (12 bytes) */
// TU: e_istaticsubmodel

extern unsigned int EIStaticSubModel_typeInfo_version;

struct EIStaticSubModel {
    unsigned int GetTypeVersion() const;
};

unsigned int EIStaticSubModel::GetTypeVersion() const {
    return EIStaticSubModel_typeInfo_version;
}
