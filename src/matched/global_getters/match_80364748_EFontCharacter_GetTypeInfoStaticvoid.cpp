// 0x80364748 (12 bytes)
class EFontCharacter {
public:
    struct TypeInfo* GetTypeInfoStatic() const;
};

struct TypeInfo;
extern TypeInfo __EFontCharacter_TypeInfo;

struct TypeInfo* EFontCharacter::GetTypeInfoStatic() const {
    return &__EFontCharacter_TypeInfo;
}
