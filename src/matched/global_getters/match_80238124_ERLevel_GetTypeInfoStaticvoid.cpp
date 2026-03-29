// 0x80238124 (12 bytes)
class ERLevel {
public:
    struct TypeInfo* GetTypeInfoStatic() const;
};

struct TypeInfo;
extern TypeInfo __ERLevel_TypeInfo;

struct TypeInfo* ERLevel::GetTypeInfoStatic() const {
    return &__ERLevel_TypeInfo;
}
