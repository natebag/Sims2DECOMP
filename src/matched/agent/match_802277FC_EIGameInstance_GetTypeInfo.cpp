/* EIGameInstance::GetTypeInfo(void) const - 0x802277FC (12 bytes) */
// TU: e_igameinstance

struct TypeInfo;

extern TypeInfo EIGameInstance_typeInfo;

struct EIGameInstance {
    const TypeInfo* GetTypeInfo() const;
};

const TypeInfo* EIGameInstance::GetTypeInfo() const {
    return &EIGameInstance_typeInfo;
}
