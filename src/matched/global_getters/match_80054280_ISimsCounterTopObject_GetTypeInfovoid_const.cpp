// 0x80054280 (12 bytes)
class ISimsCounterTopObject {
public:
    struct TypeInfo* GetTypeInfo() const;
};

struct TypeInfo;
extern TypeInfo __ISimsCounterTopObject_TypeInfo;

struct TypeInfo* ISimsCounterTopObject::GetTypeInfo() const {
    return &__ISimsCounterTopObject_TypeInfo;
}
