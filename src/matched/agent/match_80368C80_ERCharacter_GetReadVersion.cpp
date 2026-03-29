/* ERCharacter::GetReadVersion(void) - 0x80368C80 (12 bytes) */
// TU: e_rcharacter

extern unsigned int ERCharacter_readVersion;

struct ERCharacter {
    static unsigned int GetReadVersion();
};

unsigned int ERCharacter::GetReadVersion() {
    return ERCharacter_readVersion;
}
