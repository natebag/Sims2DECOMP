// 0x80364730 (12 bytes)
class EFontCharacter {
public:
    const char* GetTypeKey() const;
};

extern char gEFontCharacterData[];

const char* EFontCharacter::GetTypeKey() const {
    return *(const char**)(gEFontCharacterData + 0);
}
