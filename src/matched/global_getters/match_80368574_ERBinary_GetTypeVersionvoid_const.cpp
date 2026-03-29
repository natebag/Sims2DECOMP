// 0x80368574 (12 bytes)
class ERBinary {
public:
    short GetTypeVersion() const;
};

extern char gERBinaryData[];

short ERBinary::GetTypeVersion() const {
    return *(short*)(gERBinaryData + 0);
}
