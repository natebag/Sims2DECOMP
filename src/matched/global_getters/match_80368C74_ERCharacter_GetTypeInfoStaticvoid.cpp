// 0x80368C74 (12 bytes)
class ERCharacter {
public:
    struct TypeInfo* GetTypeInfoStatic() const;
};

struct TypeInfo;
extern TypeInfo __ERCharacter_TypeInfo;

struct TypeInfo* ERCharacter::GetTypeInfoStatic() const {
    return &__ERCharacter_TypeInfo;
}
