// 0x8005428C (12 bytes)
class ISimsCounterTopObject {
public:
    const char* GetTypeName() const;
};

extern char gISimsCounterTopObjectData[];

const char* ISimsCounterTopObject::GetTypeName() const {
    return *(const char**)(gISimsCounterTopObjectData + 0);
}
