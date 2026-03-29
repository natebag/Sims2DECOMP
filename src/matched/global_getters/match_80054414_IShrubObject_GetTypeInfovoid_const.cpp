// 0x80054414 (12 bytes)
class IShrubObject {
public:
    struct TypeInfo* GetTypeInfo() const;
};

struct TypeInfo;
extern TypeInfo __IShrubObject_TypeInfo;

struct TypeInfo* IShrubObject::GetTypeInfo() const {
    return &__IShrubObject_TypeInfo;
}
