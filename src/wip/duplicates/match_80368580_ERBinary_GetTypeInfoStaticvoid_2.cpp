// 0x80368580 (12 bytes)
class ERBinary {
public:
    struct TypeInfo* GetTypeInfoStatic() const;
};

struct TypeInfo;
extern TypeInfo __ERBinary_TypeInfo;

struct TypeInfo* ERBinary::GetTypeInfoStatic() const {
    return &__ERBinary_TypeInfo;
}
