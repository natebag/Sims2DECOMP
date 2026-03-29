// 0x80364718 (12 bytes)
class EFontCharacter {
public:
    struct TypeInfo* GetTypeInfo() const;
};

struct TypeInfo;
extern TypeInfo __EFontCharacter_TypeInfo;

struct TypeInfo* EFontCharacter::GetTypeInfo() const {
    return &__EFontCharacter_TypeInfo;
}
