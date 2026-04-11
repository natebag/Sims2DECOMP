/* ERCharacter::GetTypeKey(void) const - 0x80368C5C (12 bytes) */
// TU: e_rcharacter

extern unsigned int ERCharacter_typeInfo_key;

struct ERCharacter {
    unsigned int GetTypeKey() const;
};

unsigned int ERCharacter::GetTypeKey() const {
    return ERCharacter_typeInfo_key;
}
