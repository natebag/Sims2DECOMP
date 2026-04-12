// 0x80368568 match_80368568_ERBinary_GetTypeKey (12b)
// 0x80368568 ERBinary::GetTypeKey (12b)
// TU: e_rbinary

struct TypeInfo {
    char pad[0x10];
    unsigned int m_key;
};

extern TypeInfo ERBinary_typeInfo;

struct ERBinary {
    unsigned int GetTypeKey() const;
};

unsigned int ERBinary::GetTypeKey() const {
    return ERBinary_typeInfo.m_key;
}
