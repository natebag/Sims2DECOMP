/* ERCharacter::GetTypeInfo(void) const - 0x80368C44 (12 bytes) */
// TU: e_rcharacter

struct TypeInfo;

extern TypeInfo ERCharacter_typeInfo;

struct ERCharacter {
    const TypeInfo* GetTypeInfo() const;
};

const TypeInfo* ERCharacter::GetTypeInfo() const {
    return &ERCharacter_typeInfo;
}
