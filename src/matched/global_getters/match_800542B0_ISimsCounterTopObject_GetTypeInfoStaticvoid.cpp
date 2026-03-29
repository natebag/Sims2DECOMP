// 0x800542B0 (12 bytes)
class ISimsCounterTopObject {
public:
    struct TypeInfo* GetTypeInfoStatic() const;
};

struct TypeInfo;
extern TypeInfo __ISimsCounterTopObject_TypeInfo;

struct TypeInfo* ISimsCounterTopObject::GetTypeInfoStatic() const {
    return &__ISimsCounterTopObject_TypeInfo;
}
