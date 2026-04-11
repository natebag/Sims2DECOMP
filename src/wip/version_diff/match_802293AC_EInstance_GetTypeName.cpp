/* EInstance::GetTypeName(void) const - 0x802293AC (12 bytes) */
// TU: e_instance

struct TypeInfo;

extern char EInstance_typeInfo_name;

struct EInstance {
    const char* GetTypeName() const;
};

const char* EInstance::GetTypeName() const {
    return &EInstance_typeInfo_name;
}
