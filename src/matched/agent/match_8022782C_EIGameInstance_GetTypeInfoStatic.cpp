/* EIGameInstance::GetTypeInfoStatic(void) - 0x8022782C (12 bytes) */
// TU: e_igameinstance

struct TypeInfo;

extern TypeInfo EIGameInstance_typeInfo;

struct EIGameInstance {
    static const TypeInfo* GetTypeInfoStatic();
};

const TypeInfo* EIGameInstance::GetTypeInfoStatic() {
    return &EIGameInstance_typeInfo;
}
