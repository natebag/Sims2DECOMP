// 0x80368C80 (12 bytes)
class ERCharacter {
public:
    short GetReadVersion() const;
};

extern char gERCharacterData[];

short ERCharacter::GetReadVersion() const {
    return *(short*)(gERCharacterData + 0);
}
