/* ESim::GetTypeInfo(void) const - 0x800350F0 (12 bytes) */

struct TypeInfo;

extern TypeInfo ESim_typeInfo;

struct ESim {
    const TypeInfo* GetTypeInfo() const;
};

const TypeInfo* ESim::GetTypeInfo() const {
    return &ESim_typeInfo;
}
