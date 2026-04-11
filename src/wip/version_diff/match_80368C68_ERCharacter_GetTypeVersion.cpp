/* ERCharacter::GetTypeVersion(void) const - 0x80368C68 (12 bytes) */
// TU: e_rcharacter

extern unsigned int ERCharacter_typeInfo_version;

struct ERCharacter {
    unsigned int GetTypeVersion() const;
};

unsigned int ERCharacter::GetTypeVersion() const {
    return ERCharacter_typeInfo_version;
}
