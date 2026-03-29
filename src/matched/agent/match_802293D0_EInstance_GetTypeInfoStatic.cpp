/* EInstance::GetTypeInfoStatic(void) - 0x802293D0 (12 bytes) */
// TU: e_instance

struct TypeInfo;

extern TypeInfo EInstance_typeInfo;

struct EInstance {
    static const TypeInfo* GetTypeInfoStatic();
};

const TypeInfo* EInstance::GetTypeInfoStatic() {
    return &EInstance_typeInfo;
}
