// 0x80054444 (12 bytes)
class IShrubObject {
public:
    struct TypeInfo* GetTypeInfoStatic() const;
};

struct TypeInfo;
extern TypeInfo __IShrubObject_TypeInfo;

struct TypeInfo* IShrubObject::GetTypeInfoStatic() const {
    return &__IShrubObject_TypeInfo;
}
