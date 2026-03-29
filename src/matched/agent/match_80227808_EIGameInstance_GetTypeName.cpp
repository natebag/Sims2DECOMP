/* EIGameInstance::GetTypeName(void) const - 0x80227808 (12 bytes) */
// TU: e_igameinstance

extern char EIGameInstance_typeInfo_name;

struct EIGameInstance {
    const char* GetTypeName() const;
};

const char* EIGameInstance::GetTypeName() const {
    return &EIGameInstance_typeInfo_name;
}
