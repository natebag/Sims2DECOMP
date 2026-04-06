// 0x8036486C EFontPage::GetTypeInfo (12b)

struct TypeInfo;
extern TypeInfo g_EFontPageTypeInfo;

struct EFontPage {
    const TypeInfo* GetTypeInfo() const;
};

const TypeInfo* EFontPage::GetTypeInfo() const {
    return &g_EFontPageTypeInfo;
}
