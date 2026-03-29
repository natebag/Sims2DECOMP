// 0x80054298 (12 bytes)
class ISimsCounterTopObject {
public:
    const char* GetTypeKey() const;
};

extern char gISimsCounterTopObjectData[];

const char* ISimsCounterTopObject::GetTypeKey() const {
    return *(const char**)(gISimsCounterTopObjectData + 0);
}
