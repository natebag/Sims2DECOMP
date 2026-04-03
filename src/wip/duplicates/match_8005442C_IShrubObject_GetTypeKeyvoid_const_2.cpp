// 0x8005442C (12 bytes)
class IShrubObject {
public:
    const char* GetTypeKey() const;
};

extern char gIShrubObjectData[];

const char* IShrubObject::GetTypeKey() const {
    return *(const char**)(gIShrubObjectData + 0);
}
