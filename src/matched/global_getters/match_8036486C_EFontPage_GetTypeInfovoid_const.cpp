// 0x8036486C (12 bytes)
class EFontPage {
public:
    struct TypeInfo* GetTypeInfo() const;
};

struct TypeInfo;
extern TypeInfo __EFontPage_TypeInfo;

struct TypeInfo* EFontPage::GetTypeInfo() const {
    return &__EFontPage_TypeInfo;
}
