// 0x80368568 (12 bytes)
class ERBinary {
public:
    const char* GetTypeKey() const;
};

extern char gERBinaryData[];

const char* ERBinary::GetTypeKey() const {
    return *(const char**)(gERBinaryData + 0);
}
