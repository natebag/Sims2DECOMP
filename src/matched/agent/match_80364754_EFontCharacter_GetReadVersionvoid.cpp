// 0x80364754 (12 bytes)
class EFontCharacter {
public:
    unsigned short GetReadVersion() const;
};

extern unsigned short gEFontCharacterData[];

unsigned short EFontCharacter::GetReadVersion() const {
    return gEFontCharacterData[1];
}
