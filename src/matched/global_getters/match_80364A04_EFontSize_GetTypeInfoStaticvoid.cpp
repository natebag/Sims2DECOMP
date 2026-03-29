// 0x80364A04 (12 bytes)
class EFontSize {
public:
    struct TypeInfo* GetTypeInfoStatic() const;
};

struct TypeInfo;
extern TypeInfo __EFontSize_TypeInfo;

struct TypeInfo* EFontSize::GetTypeInfoStatic() const {
    return &__EFontSize_TypeInfo;
}
