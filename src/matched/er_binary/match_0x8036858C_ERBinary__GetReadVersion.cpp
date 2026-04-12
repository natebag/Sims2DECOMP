// 0x8036858C (12 bytes)
class ERBinary {
public:
    unsigned short GetReadVersion() const;
};

extern unsigned short ERBinary_readVersion[];

unsigned short ERBinary::GetReadVersion() const {
    return ERBinary_readVersion[0];
}
