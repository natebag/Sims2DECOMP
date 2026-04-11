/* EIStaticSubModel::GetTypeKey(void) const - 0x8022F7F0 (12 bytes) */
// TU: e_istaticsubmodel

extern unsigned int EIStaticSubModel_typeInfo_key;

struct EIStaticSubModel {
    unsigned int GetTypeKey() const;
};

unsigned int EIStaticSubModel::GetTypeKey() const {
    return EIStaticSubModel_typeInfo_key;
}
