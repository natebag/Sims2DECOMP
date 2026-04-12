// 0x8036855C match_8036855C_ERBinary_GetTypeName (12b)
// 0x8036855C ERBinary::GetTypeName (12b)
// TU: e_rbinary

struct TypeInfo {
    char pad[0x0C];
    const char* m_name;
};

extern TypeInfo ERBinary_typeInfo;

struct ERBinary {
    const char* GetTypeName() const;
};

const char* ERBinary::GetTypeName() const {
    return ERBinary_typeInfo.m_name;
}
