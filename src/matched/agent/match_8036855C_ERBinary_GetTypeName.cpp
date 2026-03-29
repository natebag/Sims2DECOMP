/* ERBinary::GetTypeName(void) const - 0x8036855C (12 bytes) */
// TU: e_rbinary

extern char ERBinary_typeInfo_name;

struct ERBinary {
    const char* GetTypeName() const;
};

const char* ERBinary::GetTypeName() const {
    return &ERBinary_typeInfo_name;
}
