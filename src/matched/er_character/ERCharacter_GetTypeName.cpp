// 0x80368C50 ERCharacter::GetTypeName (12b)
// TU: e_rcharacter

struct TypeInfo {
    char pad[0x0C];
    const char* m_name;
};

extern TypeInfo ERCharacter_typeInfo;

struct ERCharacter {
    const char* GetTypeName() const;
};

const char* ERCharacter::GetTypeName() const {
    return ERCharacter_typeInfo.m_name;
}
