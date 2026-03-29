/* ERCharacter::GetTypeName(void) const - 0x80368C50 (12 bytes) */
// TU: e_rcharacter

extern char ERCharacter_typeInfo_name;

struct ERCharacter {
    const char* GetTypeName() const;
};

const char* ERCharacter::GetTypeName() const {
    return &ERCharacter_typeInfo_name;
}
