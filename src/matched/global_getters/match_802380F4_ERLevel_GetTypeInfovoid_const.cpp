// 0x802380F4 (12 bytes)
class ERLevel {
public:
    struct TypeInfo* GetTypeInfo() const;
};

struct TypeInfo;
extern TypeInfo __ERLevel_TypeInfo;

struct TypeInfo* ERLevel::GetTypeInfo() const {
    return &__ERLevel_TypeInfo;
}
