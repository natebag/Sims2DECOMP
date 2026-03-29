/* EInstance::GetTypeInfo(void) const - 0x802293A0 (12 bytes) */
// TU: e_instance

struct TypeInfo;

extern TypeInfo EInstance_typeInfo;

struct EInstance {
    const TypeInfo* GetTypeInfo() const;
};

const TypeInfo* EInstance::GetTypeInfo() const {
    return &EInstance_typeInfo;
}
