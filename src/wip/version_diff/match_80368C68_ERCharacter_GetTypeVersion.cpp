// 0x80368C68 (12 bytes)
class ERCharacter {
public:
    unsigned short GetTypeVersion() const;
};

extern unsigned short ERCharacter_typeInfo_version[];

unsigned short ERCharacter::GetTypeVersion() const {
    return ERCharacter_typeInfo_version[0];
}
