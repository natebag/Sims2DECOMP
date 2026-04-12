// 0x80368C5C ERCharacter::GetTypeKey (12b)
// TU: e_rcharacter

struct TypeInfo {
    char pad[0x10];
    unsigned int m_key;
};

extern TypeInfo ERCharacter_typeInfo;

struct ERCharacter {
    unsigned int GetTypeKey() const;
};

unsigned int ERCharacter::GetTypeKey() const {
    return ERCharacter_typeInfo.m_key;
}
