// 0x80368C5C (12 bytes)
class ERCharacter {
public:
    const char* GetTypeKey() const;
};

extern char gERCharacterData[];

const char* ERCharacter::GetTypeKey() const {
    return *(const char**)(gERCharacterData + 0);
}
