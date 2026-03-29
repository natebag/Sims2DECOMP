/* ERBinary::GetTypeInfo(void) const - 0x80368550 (12 bytes) */
// TU: e_rbinary

struct TypeInfo;

extern TypeInfo ERBinary_typeInfo;

struct ERBinary {
    const TypeInfo* GetTypeInfo() const;
};

const TypeInfo* ERBinary::GetTypeInfo() const {
    return &ERBinary_typeInfo;
}
