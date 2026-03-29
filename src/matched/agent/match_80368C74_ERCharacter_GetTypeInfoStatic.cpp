/* ERCharacter::GetTypeInfoStatic(void) - 0x80368C74 (12 bytes) */
// TU: e_rcharacter

struct TypeInfo;

extern TypeInfo ERCharacter_typeInfo;

struct ERCharacter {
    static const TypeInfo* GetTypeInfoStatic();
};

const TypeInfo* ERCharacter::GetTypeInfoStatic() {
    return &ERCharacter_typeInfo;
}
