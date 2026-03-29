// 0x80364724 (12 bytes)
class EFontCharacter {
public:
    const char* GetTypeName() const;
};

extern char gEFontCharacterData[];

const char* EFontCharacter::GetTypeName() const {
    return *(const char**)(gEFontCharacterData + 0);
}
