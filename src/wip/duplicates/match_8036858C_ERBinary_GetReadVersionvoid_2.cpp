// 0x8036858C (12 bytes)
class ERBinary {
public:
    short GetReadVersion() const;
};

extern char gERBinaryData[];

short ERBinary::GetReadVersion() const {
    return *(short*)(gERBinaryData + 0);
}
