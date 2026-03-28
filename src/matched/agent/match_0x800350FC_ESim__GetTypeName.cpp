/* ESim::GetTypeName(void) const - 0x800350FC (12 bytes) */

struct TypeInfo {
    char pad[0x0C];
    const char* m_name;
};

extern TypeInfo ESim_typeInfo;

struct ESim {
    const char* GetTypeName() const;
};

const char* ESim::GetTypeName() const {
    return ESim_typeInfo.m_name;
}
