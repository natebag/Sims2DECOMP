// 0x80368C50 (12 bytes)
class ERCharacter {
public:
    const char* GetTypeName() const;
};

extern char gERCharacterData[];

const char* ERCharacter::GetTypeName() const {
    return *(const char**)(gERCharacterData + 0);
}
