/* ERBinary::GetTypeInfoStatic(void) - 0x80368580 (12 bytes) */
// TU: e_rbinary

struct TypeInfo;

extern TypeInfo ERBinary_typeInfo;

struct ERBinary {
    static const TypeInfo* GetTypeInfoStatic();
};

const TypeInfo* ERBinary::GetTypeInfoStatic() {
    return &ERBinary_typeInfo;
}
