// 0x80054420 (12 bytes)
class IShrubObject {
public:
    const char* GetTypeName() const;
};

extern char gIShrubObjectData[];

const char* IShrubObject::GetTypeName() const {
    return *(const char**)(gIShrubObjectData + 0);
}
