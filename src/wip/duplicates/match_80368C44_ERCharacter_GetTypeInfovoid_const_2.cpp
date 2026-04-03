// 0x80368C44 (12 bytes)
class ERCharacter {
public:
    struct TypeInfo* GetTypeInfo() const;
};

struct TypeInfo;
extern TypeInfo __ERCharacter_TypeInfo;

struct TypeInfo* ERCharacter::GetTypeInfo() const {
    return &__ERCharacter_TypeInfo;
}
