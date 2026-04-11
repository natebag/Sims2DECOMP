// 0x80364754 (12 bytes)
class EFontCharacter {
public:
    short GetReadVersion() const;
};

extern char gEFontCharacterData[];

short EFontCharacter::GetReadVersion() const {
    return *(short*)(gEFontCharacterData + 0);
}
