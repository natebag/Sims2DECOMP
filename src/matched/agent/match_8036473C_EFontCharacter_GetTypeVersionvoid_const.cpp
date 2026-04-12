// 0x8036473C (12 bytes)
class EFontCharacter {
public:
    unsigned short GetTypeVersion() const;
};

extern unsigned short gEFontCharacterData[];

unsigned short EFontCharacter::GetTypeVersion() const {
    return gEFontCharacterData[0];
}
