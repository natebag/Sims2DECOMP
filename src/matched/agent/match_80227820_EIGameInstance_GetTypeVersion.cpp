/* EIGameInstance::GetTypeVersion(void) const - 0x80227820 (12 bytes) */
// TU: e_igameinstance

extern unsigned int EIGameInstance_typeInfo_version;

struct EIGameInstance {
    unsigned int GetTypeVersion() const;
};

unsigned int EIGameInstance::GetTypeVersion() const {
    return EIGameInstance_typeInfo_version;
}
