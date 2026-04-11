/* EIGameInstance::GetTypeKey(void) const - 0x80227814 (12 bytes) */
// TU: e_igameinstance

extern unsigned int EIGameInstance_typeInfo_key;

struct EIGameInstance {
    unsigned int GetTypeKey() const;
};

unsigned int EIGameInstance::GetTypeKey() const {
    return EIGameInstance_typeInfo_key;
}
