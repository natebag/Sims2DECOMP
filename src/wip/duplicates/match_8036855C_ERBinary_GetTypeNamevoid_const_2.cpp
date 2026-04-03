// 0x8036855C (12 bytes)
class ERBinary {
public:
    const char* GetTypeName() const;
};

extern char gERBinaryData[];

const char* ERBinary::GetTypeName() const {
    return *(const char**)(gERBinaryData + 0);
}
