// 0x8036473C (12 bytes)
class EFontCharacter {
public:
    short GetTypeVersion() const;
};

extern char gEFontCharacterData[];

short EFontCharacter::GetTypeVersion() const {
    return *(short*)(gEFontCharacterData + 0);
}
