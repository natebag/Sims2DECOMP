// 0x80368C80 (12 bytes)
class ERCharacter {
public:
    unsigned short GetReadVersion() const;
};

extern unsigned short ERCharacter_readVersion[];

unsigned short ERCharacter::GetReadVersion() const {
    return ERCharacter_readVersion[0];
}
