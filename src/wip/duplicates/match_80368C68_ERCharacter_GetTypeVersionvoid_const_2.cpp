// 0x80368C68 (12 bytes)
class ERCharacter {
public:
    short GetTypeVersion() const;
};

extern char gERCharacterData[];

short ERCharacter::GetTypeVersion() const {
    return *(short*)(gERCharacterData + 0);
}
