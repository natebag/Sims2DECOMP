// 0x80368550 (12 bytes)
class ERBinary {
public:
    struct TypeInfo* GetTypeInfo() const;
};

struct TypeInfo;
extern TypeInfo __ERBinary_TypeInfo;

struct TypeInfo* ERBinary::GetTypeInfo() const {
    return &__ERBinary_TypeInfo;
}
