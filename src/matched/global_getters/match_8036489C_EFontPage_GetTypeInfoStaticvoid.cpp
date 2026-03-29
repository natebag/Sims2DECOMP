// 0x8036489C (12 bytes)
class EFontPage {
public:
    struct TypeInfo* GetTypeInfoStatic() const;
};

struct TypeInfo;
extern TypeInfo __EFontPage_TypeInfo;

struct TypeInfo* EFontPage::GetTypeInfoStatic() const {
    return &__EFontPage_TypeInfo;
}
