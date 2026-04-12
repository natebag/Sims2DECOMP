// 0x80368574 (12 bytes)
class ERBinary {
public:
    unsigned short GetTypeVersion() const;
};

extern unsigned short ERBinary_typeInfo_version[];

unsigned short ERBinary::GetTypeVersion() const {
    return ERBinary_typeInfo_version[0];
}
